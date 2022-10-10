#include "bank.h"


int main(int argc,const char* argv[])
{
	//	登录
	int msqid = msgget(ftok(".",666),0);
	if(0 > msqid)
	{
		perror("msgget");	
		return -1;
	}
	//	接收消息
	Customer cus={};	
	Server ser={};
	Account acct={};

	for(;;)
	{
		if(0 <= msgrcv(msqid,&cus,sizeof(Customer),3,0))
		{
			//	登录
			printf("登录\n");
			ser.mtype = (long)cus.pid;
			
			//	生成账户文件路径
			char path[20]="./file/";
			strcat(path,cus.acct.account_nub);

			//	寻找账户文件
			FILE* frp = fopen(path,"r+");
			//	未找到该帐户
			if(NULL == frp)
			{
				perror("frp");
				//	发送提示信息
				strcpy(ser.tip,"未找到该账户!");
				
			}
			//	找到该账户
			else
			{	
				//	读取信息到acct结构体变量中
				int lock_flag = 0;
				fscanf(frp,"%s %s %s %lf %d",acct.account_nub,acct.identity_card,acct.password,
											   &acct.money,&lock_flag);
				acct.lock_state = lock_flag;
				//	账户未锁定且未收到锁定信号
				if(!acct.lock_state && !cus.acct.lock_state)
				{
					//	密码正确
					if(0 == strcmp(cus.acct.password,acct.password))
					{
						strcpy(ser.tip,"登录成功!");
		
					}
					//	密码错误
					else
					{
						strcpy(ser.tip,"密码错误!");
				
					}
				}
				//	账户未锁定且收到锁定信号
				else if(!acct.lock_state && cus.acct.lock_state)
				{
					//acct.lock_state = true; 	//锁定账户
					
					//	重新写入数据
					fseek(frp,0,SEEK_SET);
					lock_flag = 1;
					
					fprintf(frp,"%s %s %s %.2lf %d",acct.account_nub,acct.identity_card,acct.password,
											   acct.money,lock_flag);
					fclose(frp);

					
					strcpy(ser.tip,"帐号已被锁定!");
				
				}
				//	账户锁定
				else
				{
					strcpy(ser.tip,"帐号处于锁定状态!");
				}
		
	
			}
			if(msgsnd(msqid,&ser,strlen(ser.tip)+1,0))
			{
				perror("msgsnd");
			}	
			
		}

	}

		
}
