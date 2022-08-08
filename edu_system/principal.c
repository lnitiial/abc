#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "pri_func.h"
#include "principal.h"
#include "system.h"
#include "all_tools.h"

void enter_pri(void)//进入校长页面
{
	int i=is_enter_pri();//判断是否能进入系统，且返回该学生的下标
	char new_pass[20];//修改的密码
	char new_pass_ag[20];//确定修改的密码
	while(i>=0)
	{	
		//判断输入密码是否正确
		if(true == Pri->is_first)
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
				input_password(new_pass);	//输入密码，且限制长度
				stdin->_IO_read_ptr = stdin->_IO_read_end;	//清空缓冲区
				printf("请再次确定修改后的密码（长度在3～20位之间）：");
				input_password(new_pass_ag);		//确定输入的密码，且限制长度
			}
			strcpy(Pri->password,new_pass_ag);//新密码覆盖旧密码，完成修改
			msg_show("修改成功！",1.5);
			Pri->is_first=false;		//将该学生的当前状态修改为不是第一次登录
		}
		
		//显示主界面	
		for(;;)
		{
			switch(pri_menu())
			{
				case '1': reset_pri();break;//重置校长密码
				case '2': reset_tea();break;//重置老师密码
				case '3': add_tea();break;//增加老师
				case '4': del_tea();break;//删除老师
				case '5': show_onjob();break;//显示在职教师
				case '6': show_quitjob();break;//显示离职老师
				case '7': unlock_tea();break;//解锁老师帐号
				case 'q': printf("退出成功！\n");return ;//退出
			}
		}
	}
	
	
	
}


