#include "bank.h"


int main(int argc,const char* argv[])
{
	//	开户
	int msqid = msgget(ftok(".",666),0);
	if(0 > msqid)
	{
		perror("msgget");	
		return -1;
	}
	//	接收消息
	Customer cus={};	
	Server ser={};
	

	for(;;)
	{

		if(0 <= msgrcv(msqid,&cus,sizeof(Customer),1,0))
		{
			//	读取账户编号数,防止账户重复
			FILE* frp = fopen("./file/account_nub","r+");
			if(NULL == frp)
			{
				perror("frp_open");
				return -1;
			}
			int account_nub = -1;
			fscanf(frp,"%d",&account_nub);

			//	自动生成账户帐号
			sprintf(cus.acct.account_nub,"2022%04d",account_nub++);
			printf("账户%s已开通\n",cus.acct.account_nub);
			
			//	将编号重新写入
			fseek(frp,0,SEEK_SET);
			fprintf(frp,"%d",account_nub);
			fclose(frp);
			
			//	生成账户文件路径
			char path[20]="./file/";
			strcat(path,cus.acct.account_nub);

			//	生成账户文件
			FILE* fwp = fopen(path,"w");
			if(NULL == fwp)
			{
				perror("fwp");	
				return -1;
			}
			//	写入账号、身份证号、密码、账户金额、锁定状态信息
			fprintf(fwp,"%s %s %s %.2lf %d",cus.acct.account_nub,cus.acct.identity_card,cus.acct.password,
											cus.acct.money,cus.acct.lock_state);
			fclose(fwp);	

			//	发送提示信息
			ser.mtype = (long)cus.pid;
			strcpy(ser.tip,"开户成功!");
			if(msgsnd(msqid,&ser,strlen(ser.tip)+1,0))
			{
				perror("msgsnd");
			}
			
		}

	}
		
}
