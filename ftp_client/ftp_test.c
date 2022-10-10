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

typedef struct sockaddr* SP;

int main(int argc,const char* argv[])
{
	int cmd_sock = socket(AF_INET,SOCK_STREAM,0);
	if(0 > cmd_sock)
	{
		perror("socket");	
		return EXIT_FAILURE;
	}
	struct sockaddr_in svr_addr = {};
	svr_addr.sin_family = AF_INET;
	svr_addr.sin_port = htons(21);
	svr_addr.sin_addr.s_addr = inet_addr("192.168.253.13");
	socklen_t addrlen = sizeof(svr_addr);

	if(connect(cmd_sock,(SP)&svr_addr,addrlen))
	{
		perror("connect");	
		return EXIT_FAILURE;
	}

	char buf[4096] = {};
	int ret = 0;
	size_t buf_size = sizeof(buf);

	recv(cmd_sock,buf,buf_size,0);
	printf("%s\n",buf);
	sscanf(buf,"%d",&ret);
	if(220 != ret)
	{
		printf("连接服务器失败！\n");
		return EXIT_FAILURE;
	}
	
	char name[20] = {};
	printf("请输入用户名：");
	scanf("%s",name);

	sprintf(buf,"USER %s\n",name);		//	FTP命令以\n为结束标志
	send(cmd_sock,buf,strlen(buf),0);
	recv(cmd_sock,buf,buf_size,0);
	printf("%s\n",buf);
	sscanf(buf,"%d",&ret);
	if(331 != ret)
	{
		printf("用户名有误！\n");
		return EXIT_FAILURE;
	}
	
	char pass[20] = {};
	printf("请输入密码：");
	scanf("%s",pass);
	sprintf(buf,"PASS %s\n",pass);

	send(cmd_sock,buf,strlen(buf),0);
	recv(cmd_sock,buf,buf_size,0);
	printf("%s\n",buf);
	sscanf(buf,"%d",&ret);
	if(230 != ret)
	{
		printf("密码错误！\n");
		return EXIT_FAILURE;
	}
	printf("登录成功!\n");

	//	上传
	unsigned char ip1,ip2,ip3,ip4,port1,port2;
	sprintf(buf,"PASV\n");
	send(cmd_sock,buf,strlen(buf),0);
	recv(cmd_sock,buf,buf_size,0);
	printf("%s\n",buf);
	sscanf(buf,"%d",&ret);
	if(227 != ret)
	{
		printf("数据通道打开失败!\n");
		return EXIT_FAILURE;
	}

	sscanf(buf,"227 Entering Passive Mode (%hhu,%hhu,%hhu,%hhu,%hhu,%hhu)",&ip1,&ip2,&ip3,&ip4,&port1,&port2);
	char ip[16] = {};
	sprintf(ip,"%hhu.%hhu.%hhu.%hhu",ip1,ip2,ip3,ip4);
	
	unsigned short port = port1*256+port2;

	int pasv_sock = socket(AF_INET,SOCK_STREAM,0);
	if(0 > pasv_sock)
	{
		perror("socket");
		return EXIT_FAILURE;
	}

	svr_addr.sin_port = htons(port);
	if(connect(pasv_sock,(SP)&svr_addr,addrlen))
	{
		perror("连接数据通道失败\n");
		return EXIT_FAILURE;
	}
	sprintf(buf,"STOR hello.c\n");
	send(cmd_sock,buf,strlen(buf),0);
	
	//	上传文件
	int fd = open("hello.c",O_RDONLY);
	if(0 > fd)
	{
		printf("文件不存在，请检查！\n");
		return EXIT_FAILURE;
	}
	while(ret = read(fd,buf,buf_size))
	{
		send(pasv_sock,buf,ret,0);
	}
	close(fd);
	close(pasv_sock);
		
	bzero(buf,buf_size);
	recv(cmd_sock,buf,buf_size,0);
	printf("%s\n",buf);
	sscanf(buf,"%d",&ret);
	if(150 != ret)
	{
		printf("数据通道打开失败!\n");
		return EXIT_FAILURE;
	}

	bzero(buf,buf_size);
	recv(cmd_sock,buf,buf_size,0);
	printf("%s\n",buf);
	sscanf(buf,"%d",&ret);
	if(226 != ret)
	{
		printf("数据发送有误!\n");
		return EXIT_FAILURE;
	}
	printf("文件上传成功!\n");


}
