#include "bank.h"


int main(int argc,const char* argv[])
{
	//	取款
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

		if(0 <= msgrcv(msqid,&cus,sizeof(Customer),6,0))
		{
			printf("取款\n");
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
				//	金额运算
				acct.money-=cus.acct.money;
				strcpy(ser.tip,"取款成功!");
				
			}
			else
			{
				strcpy(ser.tip,"余额不足!");	
			}
			
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
