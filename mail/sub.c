#include <stdio.h>
#include <string.h>
#include "sub.h"
#include "tool.h"

char name[50][20]; 	// 姓名
char sex[50];		// 性别
char tel[50][12]; 	// 电话
int count = 0;		// 有效联系人数量


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
