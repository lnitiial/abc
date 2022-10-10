#include <stdio.h>
#include <unistd.h>
#include <getch.h>
#include <stdlib.h>
#include "Cli_tools.h"


//	打印主菜单
int menu(void)
{
	system("clear");
	puts("****欢迎使用只因银行客户端****");
	puts("1、开通账户");
	puts("2、注销账户");
	puts("3、登录账户");
	puts("4、解锁账户");
	puts("5、退卡");
	puts("*************************");
	printf("请输入指令:");
	char cmd = getch();
	printf("%c\n",cmd);		// 回显
	return cmd;
}

//	二级菜单
int menu_2(void)
{
	system("clear");
	puts("****欢迎使用只因银行业务系统****");
	puts("1、存款");
	puts("2、取款");
	puts("3、转账");
	puts("4、查询信息");
	puts("5、修改密码");
	puts("q、主界面");
	puts("*************************");
	printf("请输入指令:");
	char cmd = getch();
	printf("%c\n",cmd);
	return cmd;

}




// 打印提示信息
void msg_show(const char* msg,float sec)
{
	printf("%s",msg);
	fflush(stdout);
	usleep(sec*1000000);

}
//	按任意键继续
void anykey_continue(void)
{
	puts("按任意键继续...");
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	getch();
}

//密码输入 将回显代替为'*'
char* input_password(char* key)
{
    char ch; 
    int i=0; 	//判断输入个数
    while(1)
    {
        ch = getch();  //每次输入单个字符，无回显 
        if(127 == ch) //判断退格键
        {
            if(i>0)
            {
                i--;
                printf("\b \b");
            }
        }
        else if('\n' == ch) //判断回车键
        {
            	printf("\n");
            	break; 
        }
        else if(i<19)  //判断字符个数是否小于20,密码个数不超过19个
        {
            key[i++]=ch;
            printf("*"); //将所有密码显示为'*'
        }
    }
    key[i]='\0';  //末尾添加结束标志'\0'
    return key;  //链式调用
}

//带数目限制功能的输入函数
char* input_words(char* key,int len)
{
    char ch; 
    int i=0; 	//判断输入个数
    while(1)
    {
        ch = getch();  //每次输入单个字符，无回显 
        if(127 == ch ) //判断退格键
        {
            if(i>0)
            {
                i--;
                printf("\b \b");
            }
        }
        else if('\n' == ch) //判断回车键
        {
            printf("\n");
            break;
        }
        else if(i<len)  //判断帐号字符个数是否小于9,密码个数不超过8个
        {
            key[i++]=ch;
            printf("%c",ch); //帐号显示
            
        }
    }
    key[i]='\0';  //末尾添加结束标志'\0'
    return key;  //链式调用
}



//	发送消息队列并接受 cus发送数据的结构体变量地址	ser接受数据的结构体变量地址
void msg_snd_rcv(int msqid,long type,Customer* cus,Server* ser)
{
	cus->mtype = type;
	cus->pid = getpid();
	if(msgsnd(msqid,cus,sizeof(Account)+sizeof(pid_t),0))	
	{
		perror("msgsnd");	
		return;
	}
	msgrcv(msqid,ser,sizeof(Server),getpid(),0);
}



