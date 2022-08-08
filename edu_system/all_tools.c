#include <stdio.h>
#include <stdlib.h>
#include <getch.h>
#include <string.h>
#include <unistd.h>
#include "system.h"
#include "all_tools.h"
//按任意键继续
void anykey_continue(void)
{
	puts("按任意键继续...");
	stdin->_IO_read_ptr = stdin->_IO_read_end;//清除缓冲区
	getch();
}
//打印提示信息
void msg_show(const char* msg,float sec)
{
	printf("%s",msg);
	fflush(stdout);
	usleep(sec*1000000);//等待1s
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



//打印学生系统菜单
int stu_menu(void)
{
	system("clear");
	printf("-----------------------------\n");
	printf("|          学生系统         |\n");
	printf("|---------------------------|\n");
	printf("|   1.查询成绩	            |\n");
	printf("|   2.修改密码	            |\n");
	printf("|   3.查看个人信息	    |\n");
	printf("|   q.退出系统              |\n");
	printf("-----------------------------\n");
	printf("请输入指令:");
	char cmd = getch();
	printf("%c\n",cmd);		// 回显
	return cmd;
}
//打印教师系统菜单
int tea_menu(void)
{
	system("clear");
	printf("-----------------------------\n");
	printf("|          教师系统         |\n");
	printf("|---------------------------|\n");
	printf("|   1、添加学生信息         |\n");
	printf("|   2、删除学生信息         |\n");
	printf("|   3、查询学生信息         |\n");
	printf("|   4、修改学生信息         |\n");
	printf("|   5、录入学生成绩         |\n");
	printf("|   6、重置学生密码         |\n");
	printf("|   7、显示所有在校学生信息 |\n");
	printf("|   8、显示所有退学学生信息 |\n");
	printf("|   9、解锁学生帐号         |\n");
	printf("|   q、返回上一级           |\n");
	printf("-----------------------------\n");
	printf("请输入指令:");
	char cmd = getch();
	printf("%c\n",cmd);		// 回显
	return cmd;
}



//打印校长系统菜单
int pri_menu(void)
{
	printf("%s\n",__func__);
	system("clear");
	printf("-----------------------------\n");
	printf("|          校长系统         |\n");
	printf("|---------------------------|\n");
	printf("|   1、重置校长密码         |\n");
	printf("|   2、重置老师密码         |\n");
	printf("|   3、增加老师             |\n");
	printf("|   4、删除老师             |\n");
	printf("|   5、显示在职教师         |\n");
	printf("|   6、显示离职教师         |\n");
	printf("|   7、解锁教师帐号         |\n");
	printf("|   q、退出                 |\n");
	printf("-----------------------------\n");
	printf("请输入指令:");
	char cmd = getch();
	printf("%c\n",cmd);
	return cmd;
}
//判断学生是否能进入函数
int is_enter_stu(void)
{
	int i;//用于返回该学生的下标
	char num_id[9];//用来存储输入的学号
	char num_pass[20];//用于存储输入的密码
	int repeat=0;//重复输入的次数
	int choice=0;//输入密码错误后的选择 1、重新输入 2、退出
	for(;;)
	{
		stdin->_IO_read_ptr = stdin->_IO_read_end;//清空缓冲区
		printf("请输入学号：\n");
		input_words(num_id,8);//输入帐号，并限制帐号长度
		for(i=0;i<Sum_stu;i++)
		{
			if(0 == strcmp(num_id ,Stu[i].id)  && true == Stu[i].in_school)//判断学号是否正确 学生是否在校
			{
				while(repeat <3 && true == Stu[i].cur_state)//判断输入错误的次数是否超过3次
				{
		
					printf("请输入密码：\n");
					if(0 == strcmp(input_password(num_pass),Stu[i].password))//判断密码是否正确
					{
						stdin->_IO_read_ptr = stdin->_IO_read_end;
						return i;//返回学生的下标
					}
					else
					{
						
							printf("密码输入错误！\n");
							repeat++;//输入密码错误，repeat次数++
					}
				}
				repeat=0;
				printf("您的帐号已被锁定，请找教师解锁!\n");
				Stu[i].cur_state = false;//将当前状态修改为不是第一次登录
			}
		}
		printf("输入学号不正确或者学号被注销！\n(按1:继续输入 按2:退出)：");
		scanf("%d",&choice);
		if(2 == choice)
		{
			return -1;
		}
	}	
}

//判断是否能进入教师系统
int is_enter_tea(void)
{
	int i;
	char num_id[9];
	char num_pass[20];
	int repeat=0;//重复输入的次数
	int choice=0;
	for(;;)
	{
		stdin->_IO_read_ptr = stdin->_IO_read_end;//清空缓冲区
		printf("请输入工号：\n");
		input_words(num_id,8);//输入帐号，并限制帐号长度
		for(i=0;i<Sum_tea;i++)
		{
			if(0 == strcmp(num_id ,Tea[i].id) && true == Tea[i].in_school)
			{
				stdin->_IO_read_ptr = stdin->_IO_read_end;
				while(repeat <3 && true == Tea[i].cur_state)
				{
					printf("请输入密码：\n");
					if(0 == strcmp(input_password(num_pass),Tea[i].password))
					{
						stdin->_IO_read_ptr = stdin->_IO_read_end;
						return i;//返回教师的下标
					}
					else 
					{
						printf("密码输入错误！\n");
						repeat++;//输入密码错误，repeat次数++
					}
				}
				repeat=0;
				printf("您的帐号已被锁定，请找校长解锁!\n");
				Tea[i].cur_state = false;
			}
		}
		printf("输入工号不正确或者工号已被注销！\n(按1:切换用户 按2:退出)：");
		scanf("%d",&choice);
		if(2 == choice)
		{
			return -1;
		}
	}	
}




//校长登录
int is_enter_pri(void)
{
	//printf("%s\n",__func__);
	char ch;
	char str[20]={};	//局部变量
	system("clear");
	printf("欢迎来到校长管理系统\n");
	for(;;)
	{
		printf("请输入你的密码：\n");
		stdin->_IO_read_ptr = stdin->_IO_read_end;
		if(0 == strcmp(input_password(str),Pri->password))
		{
			printf("登录成功！\n");
			return 0;
		}
		else
		{
			printf("密码错误！\n");
		}
		printf("（请选择 1.重新输入 2.退出）:");
		ch=getch();
		printf("%c\n",ch);
		switch(ch)
		{
			case '1':break;
			case '2':return -1;;
		}
	}
	
}


//编号生成 id为输出字符串, prefix前缀 suffix后缀 suf_num后缀长度 前缀可以是字符串,后缀是整形数据,位数不足在前补0
char* generate_num(char *id,const char* prefix,int suffix,int suf_num)
{
    strcpy(id,prefix);
    char str[suf_num+1];
   	str[suf_num]='\0';
    while(suf_num>=0)
    {
        str[--suf_num] = suffix%10+48;
        suffix/=10;
    }
    strcat(id,str);
    return id;
}

//fgets输入姓名函数，且功能能去除末尾的\n
char *MyFgets(char data[],int count)
{
	fgets(data,count,stdin);
	char *find = strchr(data,'\n');  //找到\n首次出现的位置
	if(find)
	{
		*find = '\0'; //替换
	}
	return data; 
}





