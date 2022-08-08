#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "tea_func.h"
#include "teacher.h"
#include "system.h"
#include "all_tools.h"

//第一次登录强制修改密码
void enter_tea(void)
{
	int i=is_enter_tea();//判断是否能进入系统，且返回该学生的下标
	char new_pass[20];//修改的密码
	char new_pass_ag[20];//确定修改的密码
	while(i>=0)
	{
		//判断输入密码是否正确
		if(true == Tea[i].is_first)
		{
			printf("由于是第一次登录，请修改密码（长度在3～20位之间）：");
			input_password(new_pass);		//输入密码，且限制长度
			stdin->_IO_read_ptr = stdin->_IO_read_end;		//清空缓冲区
			printf("请再次确定修改后的密码（长度在3～20位之间）：");
			input_password(new_pass_ag);		//确定输入的密码，且限制长度
			stdin->_IO_read_ptr = stdin->_IO_read_end;		//清空缓冲区
			while(0 != strcmp(new_pass,new_pass_ag) || 4>strlen(new_pass))//判断两次的输入的密码是否一致，且长度是否在限定范围内
			{
				printf("两次密码不一致或密码长度过短！请继续修改密码（长度在3～20位之间）：");
				input_password(new_pass);		//输入密码，且限制长度
				stdin->_IO_read_ptr = stdin->_IO_read_end;		//清空缓冲区
				printf("请再次确定修改后的密码（长度在3～20位之间）：");
				input_password(new_pass_ag);		//确定输入的密码，且限制长度
			}
			strcpy(Tea[i].password,new_pass_ag);//新密码覆盖旧密码，完成修改
			msg_show("修改成功！",1.5);
			Tea[i].is_first=false;		//将该学生的当前状态修改为不是第一次登录
		}
		
		switch(tea_menu())
		{
			case '1': tea_add();	break;		//添加学生
			case '2': tea_del();	break;		//删除学生
			case '3': tea_find();	break;		//查找学生
			case '4': tea_mod();	break;		//修改学生信息
			case '5': tea_input();  break; 		//录入学生成绩 	
			case '6': tea_reset_stu();  break;		//重置密码
			case '7': tea_display_school(); break;//显示所有在校学生信息
			case '8': tea_display_drop();	break;//显示所有退学学生信息
			case '9': tea_unlock(); break;		//解锁教师
			case 'q': return;			//退出系统
		
		}
	}
}

