#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ftp_cli.h"
#include "tools.h"



int main(int argc,const char* argv[])
{
	if(2 != argc)
	{
		printf("User:./Ftp ip\n");
		return EXIT_FAILURE;
	}
	//	连接服务器
	int cmd_sock = connect_to_server(argv[1]);
	//	发送用户名、密码
	user_login(cmd_sock);
	
	char input[256] = {};		//	用户输入
	char cmd[256] = {};			//	命令
	char par[256] = {};			//	参数
	
	
	
	
	for(;;)
	{
		printf("ftp> ");
		stdin->_IO_read_ptr = stdin->_IO_read_end;
		MyFgets(input,256);
		sscanf(input,"%s %s",cmd,par);
		
		if(0 == strcmp(cmd,"pwd"))				//	显示当前路径
		{
			pwd_command(cmd_sock);
		}
		
		else if(0 == strcmp(cmd,"mkdir"))		//	创建空目录
		{
			mkdir_command(cmd_sock,par);
		}
		
		else if(0 == strcmp(cmd,"rmdir"))		//	删除空目录
		{
			rmdir_command(cmd_sock,par);
		}
		
		else if(0 == strcmp(cmd,"cd"))			//	进入目录
		{
			cd_command(cmd_sock,par);
		}
		
		else if(0 == strcmp(cmd,"ls"))			//	显示目标文件详细信息
		{
			ls_command(cmd_sock,par);
		}
		
		else if(0 == strcmp(cmd,"put"))			//	上传
		{
			put_command(cmd_sock,par);
		}
		
		else if(0 == strcmp(cmd,"get"))			//	下载
		{
			get_command(cmd_sock,par);
		}
		
		else if(0 == strcmp(cmd,"bye"))			//	退出
		{
			bye_command(cmd_sock);
		}
		else
		{
			printf("?Invalid command\n");
		}
	}
	
	
}
