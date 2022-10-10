#include "bank.h"
#include "Cli_tools.h"
int login_acct(void);

Customer cus = {};
Server ser = {};
int msqid = 0;

int main(int argc,const char* argv[])
{
	msqid = msgget(ftok(".",666),0);
	if(0 > msqid)
	{
		perror("msgget");
		return -1;
	}

	for(;;)
	{
		switch(menu())
		{
			//	开户
			case '1':
			{
				//	获取身份证号、密码
				printf("请输入身份证号:");
				input_words(cus.acct.identity_card,18);
				printf("请输入密码:");
				input_password(cus.acct.password);
				
				//	初始化信息
				cus.acct.money=0;
				cus.acct.lock_state=false;
				
				msg_snd_rcv(msqid,1,&cus,&ser);
				msg_show(ser.tip,1.5);
			}
			break;
			//	销户
			case '2':
			{
				//	获取账户帐号、密码
				printf("请输入账户帐号:");
				input_words(cus.acct.account_nub,8);
				printf("请输入密码:");
				input_password(cus.acct.password);
				
				
				msg_snd_rcv(msqid,2,&cus,&ser);
				printf("%s\n",ser.tip);
				//	接受提示信息
				if(0 == strcmp(ser.tip,"请确认是否销户(Y/N)"))
				{
					input_words(ser.tip,1);
					ser.mtype = 2;
					if(msgsnd(msqid,&ser,strlen(ser.tip)+1,0))	
					{
						perror("msgsnd");	
					}
					msgrcv(msqid,&ser,sizeof(ser.tip),getpid(),0);
					printf("%s\n",ser.tip);
				}
			
				
				msg_show("",1.5);
			}
			break;
			//	登录
			case '3':
			{
				//	获取账户帐号、密码
				printf("请输入账户帐号:");
				input_words(cus.acct.account_nub,8);
				printf("请输入密码:");
				input_password(cus.acct.password);

				cus.acct.lock_state = false;
				msg_snd_rcv(msqid,3,&cus,&ser);
				//	密码正确
				if(0 == strcmp(ser.tip,"登录成功!"))
				{
					printf("%s\n",ser.tip);
					msg_show("",1.5);
					login_acct();
				}
				//	账户是锁定状态
				else if(0 == strcmp(ser.tip,"帐号处于锁定状态!"))
				{
					printf("%s\n",ser.tip);
					msg_show("",1.5);
	
				}
				//	帐号不存在
				else if(0 == strcmp(ser.tip,"未找到该账户!"))
				{
					printf("%s\n",ser.tip);
					msg_show("",1.5);
				}
				//	帐号未锁定且密码错误
				else
				{
					//	flag用于判断是否从登录状态返回主界面
					int flag = 0;
					
					for(int i=2; i>0 && !flag; i--)
					{
						printf("密码错误!请重新输入密码(你还剩下%d次机会):",i);
						input_password(cus.acct.password);
						msg_snd_rcv(msqid,3,&cus,&ser);
						//	三次内登录成功
						if(0 == strcmp(ser.tip,"登录成功!"))
						{
							printf("%s\n",ser.tip);
							msg_show("",1.5);
							flag = login_acct();
						}
					}
					//	
					if(flag == 0)
					{
						//	三次密码错误锁定账户
						cus.acct.lock_state = true;
						msg_snd_rcv(msqid,3,&cus,&ser);
						printf("%s\n",ser.tip);
						msg_show("",1.5);
					
					}
					
						
						
				}
				
			}
			break;
			
			//	解锁
			case '4':
			{

				printf("请输入账户帐号:");
				input_words(cus.acct.account_nub,8);
				printf("请输入身份证号:");
				input_words(cus.acct.identity_card,18);

				msg_snd_rcv(msqid,4,&cus,&ser);
				printf("%s\n",ser.tip);
				msg_show("",1.5);
			}
			break;
			
			case '5': return 0;
			
			
		}
	}
}

int login_acct(void)
{
	for(;;)
	{
		switch(menu_2())
		{
			//	存款
			case '1':
			{
				printf("请输入存款金额:");
				scanf("%lf",&cus.acct.money);
				msg_snd_rcv(msqid,5,&cus,&ser);
				printf("%s\n",ser.tip);
				msg_show("",1.5);
			
			}
			break;
			//	取款
			case '2':
			{
				printf("请输入取款金额:");
				scanf("%lf",&cus.acct.money);
				msg_snd_rcv(msqid,6,&cus,&ser);
				printf("%s\n",ser.tip);
				msg_show("",1.5);
			}	
			break;
			//	 转账
			case '3':	
			{
				printf("请输入转账账户:");
				input_words(cus.acct.identity_card,8);
				printf("请输入转转账金额:");
				scanf("%lf",&cus.acct.money);
				
				msg_snd_rcv(msqid,7,&cus,&ser);
				printf("%s\n",ser.tip);
				msg_show("",1.5);
			}
			break;
			//	查询
			case '4': 
			{
				msg_snd_rcv(msqid,8,&cus,&ser);
				printf("%s\n",ser.tip);
				anykey_continue();
			}
			break;
			//	修改
			case '5': 	
			{
				printf("请输入原密码:");
				input_password(cus.acct.password);
				printf("请输入新密码:");
				input_password(cus.acct.identity_card);

				msg_snd_rcv(msqid,9,&cus,&ser);
				printf("%s\n",ser.tip);
				msg_show("",1.5);
			
			}
			break;
			case 'q': 	return 1;
		
		}
	}
}




