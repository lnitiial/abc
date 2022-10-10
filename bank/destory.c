#include "bank.h"


int main(int argc,const char* argv[])
{
	//	销户
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

		if(0 <= msgrcv(msqid,&cus,sizeof(Customer),2,0))
		{
			printf("销户\n");
			ser.mtype = (long)cus.pid;
			
			//	生成账户文件路径
			char path[20]="./file/";
			strcat(path,cus.acct.account_nub);

			//	寻找账户文件
			FILE* frp = fopen(path,"r");
			//	未找到该帐户
			if(NULL == frp)
			{
				perror("frp");
				//	发送提示信息
				strcpy(ser.tip,"未找到该账户!");
				if(msgsnd(msqid,&ser,strlen(ser.tip)+1,0))
				{
					perror("msgsnd");
				}	
				
			}
			//	找到该账户
			else
			{	
				//	读取信息到acct结构体变量中
				int lock_flag = 0;
				fscanf(frp,"%s %s %s %lf %d",acct.account_nub,acct.identity_card,acct.password,
											   &acct.money,&lock_flag);
				acct.lock_state = lock_flag;
				//	密码正确
				if(0 == strcmp(cus.acct.password,acct.password))
				{
					
					strcpy(ser.tip,"请确认是否销户(Y/N)");
					if(msgsnd(msqid,&ser,strlen(ser.tip)+1,0))
					{
						perror("msgsnd");
					}
					//	接收确认消息
				
					if(0 <= msgrcv(msqid,&ser,sizeof(ser.tip),2,0))
					{
						printf("wait\n");
						if(0 == strcmp(ser.tip,"Y") || 0 == strcmp(ser.tip,"y"))
						{
							//	删除账户文件
						
							fclose(frp);
							remove(path);
							strcpy(ser.tip,"销户成功!");
						
							if(msgsnd(msqid,&ser,strlen(ser.tip)+1,0))
							{
								perror("msgsnd");
							}
							
						
					
						}
						else
						{
							strcpy(ser.tip,"销户失败!");	
						
							if(msgsnd(msqid,&ser,strlen(ser.tip)+1,0))
							{
								perror("msgsnd");
							}
								
						}
					}
					
	
						
			
				}
				//	密码错误
				else
				{
					
					strcpy(ser.tip,"密码错误销户失败!");
					
					if(msgsnd(msqid,&ser,strlen(ser.tip)+1,0))
					{
						perror("msgsnd");
					}	
				
				}
			

				
			}

		}

	}
		
}
