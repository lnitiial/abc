#include <stdio.h>
#include <string.h>
#include "principal.h"
#include "pri_func.h"
#include "system.h"
#include "all_tools.h"

//重置校长密码函数
void reset_pri(void)
{
	strcpy(Pri->password,PRI_INIT_PASS);//调用修改密码函数
	Pri->is_first=true;
	msg_show("重置密码成功\n",1.5);
	
}

//重置老师密码函数
void reset_tea(void)
{
	char str[9]={};
	printf("请输入你要重置密码的教师工号：\n");
	input_words(str,8);//输入帐号，并限制帐号长度
	stdin->_IO_read_ptr = stdin->_IO_read_end;//清空缓冲区
	for(int i=0;i<Sum_tea;i++)//判断名字是否相同
	{
		if(0==strcmp(str,Tea[i].id) && Tea[i].in_school)
		{
			Tea[i].is_first=true;
			strcpy(Tea[i].password,TEA_INIT_PASS);//相同则将老师的密码改为初始值
			msg_show("重置密码成功\n",1.5);//修改成功提示
			return;
		}

	}
	msg_show("查无此人\n",1.5);//不同则显示查无此人
}

//添加老师函数
void add_tea(void)
{
	debug("%s\n",__func__);
	if(MAX_TEA<=Sum_tea)//人数超过限定人数，提示用户
	{
		msg_show("系统正在升级，请等待...\n",1.5);
		return;
	}
	printf("请输入新教师的姓名:");
	MyFgets(Tea[Sum_tea].name,20);
	stdin->_IO_read_ptr = stdin->_IO_read_end;//清空缓冲区
	printf("请输入新教师的性别(w/m):");
	scanf("%c",&Tea[Sum_tea].sex);
	stdin->_IO_read_ptr = stdin->_IO_read_end;//清空缓冲区
	while('w' != Tea[Sum_tea].sex && 'm' != Tea[Sum_tea].sex)
	{
		printf("性别格式输入错误！请重新输入：");
		scanf("%c",&Tea[Sum_tea].sex);
	}
	stdin->_IO_read_ptr = stdin->_IO_read_end;//清空缓冲区
	
	Tea[Sum_tea].in_school=1;
	Tea[Sum_tea].cur_state=1;
	Tea[Sum_tea].is_first=1;
	strcpy(Tea[Sum_tea].password,TEA_INIT_PASS);//将教师的初始密码TEA_INIT_PASS赋给新教师
	Sum_tea++;
	generate_num(Tea[Sum_tea-1].id,"2207",Sum_tea,4);//学号自动生成格式为22070001
	msg_show("添加教师成功！\n",1.5);
}

//删除教师函数
void del_tea(void)
{
	debug("%s\n",__func__);
	char key[9]={};
	printf("请输入你要删除的教师的工号：\n");
	input_words(key,8);//输入帐号，并限制帐号长度
	stdin->_IO_read_ptr = stdin->_IO_read_end;//清空缓冲区
	for(int i=0;i<Sum_tea;i++)
	{
		if(true == Tea[i].in_school)//判断教师是否在职
		{
			if(0 == strcmp(key,Tea[i].id))//判断是否存在该教师
			{
				Tea[i].in_school=false;	//将该教师的在职情况改为离职			
				msg_show("删除教师成功！\n",1.5);
				return;
			}
		}
	}
	msg_show("查无此人，删除失败！\n",1.5);//未找到教师，则显示查无此人
}

//显示在职教师
void show_onjob(void)
{
	debug("%s\n",__func__);
	for(int i=0;i<Sum_tea;i++)
	{
		if(true ==Tea[i].in_school)//判断教师的在职情况是否为在职
		{
			printf("姓名：%s\t性别：%-6s工号：%s\n",Tea[i].name,'w'==Tea[i].sex?"女":"男",Tea[i].id);	
		}
	}
	anykey_continue();//按任意键继续...
}


//显示离职教师
void show_quitjob(void)
{
	debug("%s\n",__func__);
	for(int i=0;i<Sum_tea;i++)
	{
		if(false == Tea[i].in_school )//判断教师的在职情况是否为离职
		{
			printf("姓名：%s\t性别：%-6s工号：%8s\n",Tea[i].name,'w'==Tea[i].sex?"女":"男",Tea[i].id);	
		}
	}
	anykey_continue();
}

//解锁教师帐号
void unlock_tea(void)
{
	debug("%s\n",__func__);
	char str[9]={};
	printf("请输入你要解锁的教师工号：\n");
	input_words(str,8);//输入帐号，并限制帐号长度
	stdin->_IO_read_ptr = stdin->_IO_read_end;//清空缓冲区
	for(int i=0;i<Sum_tea;i++)
	{
		if(0 == strcmp(str,Tea[i].id) && true == Tea[i].in_school)//判断是否存在该在校教师，
		{
			if(false == Tea[i].cur_state)//判断该教师是否是锁定状态
			{
				Tea[i].cur_state=true;
				msg_show("解锁成功！\n",1.5);
				return;
			}
			else //判断该教师是否是未锁定状态
			{
				msg_show("该帐号未锁定或已经离校，请确认教师工号！\n",1.5);
				return;
			}
		}
	}
		
	msg_show("查无此人！\n",1.5);
}


