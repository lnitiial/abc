#include <stdio.h>
#include <stdlib.h>
#include <getch.h>
#include <unistd.h>
#include <string.h>

static char name[50][20]; 	// 姓名
static char sex[50];		// 性别
static char tel[50][12]; 	// 电话
static int count = 0;		// 有效联系人数量

int menu(void);
void add(void);
void del(void);
void mod(void);
void find(void);
void show(void);
void msg_show(const char* msg,float sec);
void anykey_continue(void);

int main(int argc,const char* argv[])
{
	for(;;)
	{
		// 显示主界面	
		switch(menu())
		{
			case '1':	add();break;
			case '2':	del();break;
			case '3':	mod();break;
			case '4':	find();break;
			case '5':	show();break;
			case '6':	return 0;
		}


	}
}


int menu(void)
{
	system("clear");
	puts("****欢迎使用学生通讯录****");
	puts("1、添加联系人");
	puts("2、删除联系人");
	puts("3、修改联系人");
	puts("4、查询联系人");
	puts("5、遍历联系人");
	puts("6、退出通讯录");
	puts("*************************");
	printf("请输入指令:");
	char cmd = getch();
	printf("%c\n",cmd);		// 回显
	return cmd;
}

void add(void)
{
	//printf("%s\n",__func__);
	if(50 <= count)
	{
		puts("系统正在升级,请等待...");
		return;
	}
	int i = 0;
	while(sex[i]) i++;
	printf("请输入新联系人姓名、性别、电话:");
	scanf("%s %c %s",name[i],&sex[i],tel[i]);
	count++;
	msg_show("添加联系人成功!\n",1.5);

}

void del(void)
{
	//printf("%s\n",__func__);
	char key[20] = {};
	printf("请输入需要删除的联系人姓名:");
	scanf("%s",key);
	
	for(int i=0;i<50;i++)
	{
		if(sex[i])
		{
			if(0 == strcmp(key,name[i]))
			{
				sex[i] = 0;		
				count--;
				msg_show("删除联系人成功\n",1.5);
				return;
			}
		}

	}
	msg_show("查无此人,删除失败!\n",1.5);
}

void mod(void)
{
	//printf("%s\n",__func__);
	char key[20] = {};
	printf("请输入需要修改的联系人姓名:");
	scanf("%s",key);
	
	for(int i=0;i<50;i++)
	{
		if(sex[i])
		{
			if(0 == strcmp(key,name[i]))
			{
				printf("请输入新联系人姓名、性别、电话:");
				scanf("%s %c %s",name[i],&sex[i],tel[i]);

				msg_show("修改联系人成功!\n",1.5);
				return;
			}
		}

	}
	msg_show("查无此人,修改失败!\n",1.5);

	
}
void find(void)
{
	//printf("%s\n",__func__);
	char key[20] = {};
	printf("请输入要查询的关键字:");
	scanf("%s",key);

	for(int i=0; i<50; i++)
	{
		if(sex[i]) 
		{
			if(strstr(name[i],key) || strstr(tel[i],key))
			{
				printf("%s %s %s\n",name[i],'w'==sex[i]?"女":"男",tel[i]);	
			}
		}
	}
	anykey_continue();
}

void show(void)
{
	//printf("%s\n",__func__);
	for(int i=0; i<50;i++)
	{
		if(sex[i])
		{
			printf("%s %s %s\n",name[i],'w'==sex[i]?"女":"男",tel[i]);	
		}
	}
	anykey_continue();
	
}
// 打印提示信息
void msg_show(const char* msg,float sec)
{
	printf("%s",msg);
	fflush(stdout);
	usleep(sec*1000000);

}
void anykey_continue(void)
{
	puts("按任意键继续...");
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	getch();
}

