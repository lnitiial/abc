#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "ftp_cli.h"
#include "tools.h"

struct sockaddr_in svr_addr={};
char addr_ip[16]={};
char buf[4096] = {};
size_t buf_size = sizeof(buf);

//	连接服务器
int connect_to_server(const char* ip)
{
	int cmd_sock = socket(AF_INET,SOCK_STREAM,0);
	if(0 > cmd_sock)
	{
		perror("sockfd");
		exit(EXIT_FAILURE);
	}
	svr_addr.sin_family = AF_INET;
	svr_addr.sin_port = htons(21);
	strcpy(addr_ip,ip);
	svr_addr.sin_addr.s_addr = inet_addr(ip);
	socklen_t addrlen = sizeof(svr_addr);

	printf("Connected to %s\n",addr_ip);

	
	if(connect(cmd_sock,(SP)&svr_addr,addrlen))
	{
		perror("connect");
		exit(EXIT_FAILURE);
	}
	
	if(220 != recv_cmd(cmd_sock,buf,buf_size))
	{
		printf("连接服务器失败！\n");
		exit(EXIT_FAILURE);
	}
	return cmd_sock;
}

//	输入账户密码登录
void user_login(int sockfd)
{
	//	输入账号
	char name[21] = {};
	printf("Name (%s:ubuntu):",addr_ip);
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	input_password(name,20,0);

	sprintf(buf,"USER %s\n",name);		//	FTP命令以\n为结束标志
	send(sockfd,buf,strlen(buf),0);
	
	if(331 != recv_cmd(sockfd,buf,buf_size))
	{
		printf("用户名有误！\n");
		exit(EXIT_FAILURE);
	}
	
	//	输入密码
	char pass[21] = {};
	printf("Password:");
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	input_password(pass,20,' ');
	sprintf(buf,"PASS %s\n",pass);
	
	send(sockfd,buf,strlen(buf),0);

	if(230 != recv_cmd(sockfd,buf,buf_size))
	{
		printf("密码错误！\n");
		exit(EXIT_FAILURE);
	}
	printf("Remote system type is UNIX.\n");
	printf("Using binary mode to transfer files.\n");
	
}
//	显示当前路径
void pwd_command(int sockfd)
{
	//printf("%s\n",__func__);
	sprintf(buf,"PWD\n");
	send(sockfd,buf,strlen(buf),0);
	if(257 != recv_cmd(sockfd,buf,buf_size))
	{
		printf("访问失败！\n");
	}
	
}
//	创建空目录
void mkdir_command(int sockfd,char* par)
{
	//printf("%s\n",__func__);
	sprintf(buf,"MKD %s\n",par);
	send(sockfd,buf,strlen(buf),0);
	if(257 != recv_cmd(sockfd,buf,buf_size))
	{
		printf("创建失败！\n");
	}

}

//	删除空目录
void rmdir_command(int sockfd,char* par)
{
	//printf("%s\n",__func__);
	sprintf(buf,"RMD %s\n",par);
	send(sockfd,buf,strlen(buf),0);
	recv_cmd(sockfd,buf,buf_size);

}
//进入目录
void cd_command(int sockfd,char* par)
{
	//printf("%s\n",__func__);
	sprintf(buf,"CWD %s\n",par);
	send(sockfd,buf,strlen(buf),0);
	recv_cmd(sockfd,buf,buf_size);
}

//显示目标文件详细信息
void ls_command(int sockfd,char* par)
{
	//printf("%s\n",__func__);
	
	int pasv_sock = PASV_cmd(sockfd);
	
	sprintf(buf,"LIST %s\n",par);
	send(sockfd,buf,strlen(buf),0);
	
	if(150 !=recv_cmd(sockfd,buf,buf_size))
	{
		printf("列表打印失败！\n");
		return;
	}
	char buf_data[256] = {};
	int ret = 0;
	while((ret = recv(pasv_sock,buf_data,sizeof(buf_data),0)))
	{
		printf("%s",buf_data);
		bzero(buf_data,sizeof(buf_data));
	}
	
	recv_cmd(sockfd,buf,buf_size);
	close(pasv_sock);
}
//	上传
void put_command(int sockfd,char*par)
{
	//printf("%s\n",__func__);
	int pasv_sock = PASV_cmd(sockfd);
	
	sprintf(buf,"STOR %s\n",par);
	send(sockfd,buf,strlen(buf),0);
	
	int fd = open(par,O_RDONLY);
	if(0 > fd)
	{
		printf("文件不存在，请检查！\n");
		return;
	}
	int ret = 0;
	while((ret = read(fd,buf,buf_size)))
	{
		send(pasv_sock,buf,ret,0);
	}
	close(fd);
	close(pasv_sock);
	
	if(150 != recv_cmd(sockfd,buf,buf_size))
	{
		printf("数据通道打开失败！\n");
		return;
	}
	
	if(226 != recv_cmd(sockfd,buf,buf_size))
	{
		printf("数据发送有误！\n");
		return;
	}
	
	
}
//	下载
void get_command(int sockfd,char* par)
{
	//printf("%s\n",__func__);
	int pasv_sock = PASV_cmd(sockfd);
	
	sprintf(buf,"RETR %s\n",par);
	send(sockfd,buf,strlen(buf),0);
	int fd = open(par,O_WRONLY|O_CREAT|O_EXCL,0644);
	if(0 > fd)
	{	
		printf("文件已存在存在，请检查！\n");
		return;
	}
	
	char buf_data[256] = {};
	int ret = 0;
	
	while((ret = recv(pasv_sock,buf_data,sizeof(buf_data),0)))
	{
		write(fd,buf_data,ret);
		bzero(buf_data,sizeof(buf_data));
	}
	
	close(fd);
	close(pasv_sock);
	
	if(150 != recv_cmd(sockfd,buf,buf_size))
	{
		printf("数据通道打开失败！\n");
		return;
	}
	
	if(226 != recv_cmd(sockfd,buf,buf_size))
	{
		printf("数据发送有误！\n");
		return;
	}
	
	
}
//	退出
void bye_command(int sockfd)
{
	//printf("%s\n",__func__);
	sprintf(buf,"QUIT\n");
	send(sockfd,buf,strlen(buf),0);
	if(221 != recv_cmd(sockfd,buf,buf_size))
	{
		printf("退出失败！\n");
	}
	close(sockfd);
	exit(EXIT_SUCCESS);
	
}



