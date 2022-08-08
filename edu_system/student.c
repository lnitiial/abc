#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "stu_func.h"
#include "student.h"
#include "all_tools.h"
#include "system.h"


void enter_stu(void)//进入学生页面
{
	int i=is_enter_stu();////判断是否能进入系统，且返回该学生的下标
	char new_pass[20];//修改的密码
	char new_pass_ag[20];//确定修改的密码
	while(i>=0)
	{
		//判断输入密码是否正确
		if(true == Stu[i].is_first)
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
			strcpy(Stu[i].password,new_pass_ag);		//新密码覆盖旧密码，完成修改
			msg_show("修改成功！",1.5);
			Stu[i].is_first=false;		//将该学生的当前状态修改为不是第一次登录
		}
			
		switch(stu_menu())
		{	
			case '1': query_score(i);break;		//查询成绩
			case '2': chang_pass(i);break;		//修改密码"
			case '3': query_infor(i);break;		//查看个人信息
			case 'q': return;					//退出系统
		
		
		}
	}
}


