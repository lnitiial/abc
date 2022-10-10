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
	Account acct1={};	

	for(;;)
	{

		if(0 <= msgrcv(msqid,&cus,sizeof(Customer),7,0))
		{
			printf("存钱\n");
			ser.mtype = (long)cus.pid;
			
			//	生成账户文件路径
			char path[20]="./file/";
			strcat(path,cus.acct.account_nub);

			//	寻找账户文件
			FILE* frp = fopen(path,"r+");
			if(frp == NULL)
			{
				perror("frp");
			}
			//	读取信息到acct结构体变量中
			int lock_flag = 0;
			fscanf(frp,"%s %s %s %lf %d",acct.account_nub,acct.identity_card,acct.password,
										   &acct.money,&lock_flag);
			acct.lock_state = lock_flag;
			if(cus.acct.money <= acct.money)
			{
			
				//	生成转账账户
				char path_1[20]="./file/";
				strcat(path_1,cus.acct.identity_card);
				//	寻找转账账户文件
				FILE* frp1 = fopen(path_1,"r+");
				{	
					//	转账账户不存在
					if(frp1 == NULL)
					{
						perror("frp1");
						strcpy(ser.tip,"转账账户不存在!");
						
					}
					else
					{
						//	读取转账文件信息
						fscanf(frp1,"%s %s %s %lf %d",acct1.account_nub,acct1.identity_card,acct1.password,
										   &acct1.money,&lock_flag);
						acct1.lock_state = lock_flag;
						//	转账
						acct.money-=cus.acct.money;
						acct1.money+=cus.acct.money;
						//	保存转账账户信息
						fseek(frp1,0,SEEK_SET);
						fprintf(frp1,"%s %s %s %.2lf %d",acct1.account_nub,acct1.identity_card,acct1.password,
									   acct1.money,acct1.lock_state);
						fclose(frp1);
						
						strcpy(ser.tip,"转账成功!");
						
					
					}
				}
				
				
			}
			else
			{
				strcpy(ser.tip,"余额不足!");	
			}
			//	发送提示信息
			if(msgsnd(msqid,&ser,strlen(ser.tip)+1,0))
			{
				perror("msgsnd");
			}
			//	重新写入数据
			fseek(frp,0,SEEK_SET);
			fprintf(frp,"%s %s %s %.2lf %d",acct.account_nub,acct.identity_card,acct.password,
									   acct.money,acct.lock_state);
			fclose(frp);
		
			
		}
	}
}
