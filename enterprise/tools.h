#ifndef TOOLS_H
#define TOOLS_H

#include <mysql/mysql.h>

void anykey_continue(void);

void msg_show(const char* msg,float sec);

int get_id(const char* path);			//	生成唯一的管理员ID号。
	
char get_cmd(char start,char end);		//	输出指定范围内的键值


#endif//TOOLS_H
