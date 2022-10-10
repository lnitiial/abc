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
#include <getch.h>
#include "ftp_cli.h"
#include "tools.h"


//	接受命令，并返回整数
int recv_cmd(int sockfd,char* buf,size_t len)
{
	int ret = 0;
	bzero(buf,len);
	recv(sockfd,buf,len,0);
	printf("%s",buf);
	sscanf(buf,"%d",&ret);
	return ret;
}

//fgets输入姓名函数，且功能能去除末尾的\n
char *MyFgets(char data[],int count)
{
	fgets(data,count,stdin);
	char *find = strchr(data,'\n');  //找到\n首次出现的位置
	if(find)
	{
		*find = '\0'; //替换
	}
	return data; 
}

int PASV_cmd(int sockfd)
{
	unsigned char ip1,ip2,ip3,ip4,port1,port2;
	sprintf(buf,"PASV\n");
	send(sockfd,buf,strlen(buf),0);
	if(227 != recv_cmd(sockfd,buf,buf_size))
	{
		printf("数据通道打开失败!\n");
		exit(EXIT_FAILURE);
	}
	sscanf(buf,"227 Entering Passive Mode (%hhu,%hhu,%hhu,%hhu,%hhu,%hhu)",&ip1,&ip2,&ip3,&ip4,&port1,&port2);

	
	unsigned short port = port1*256+port2;

	int pasv_sock = socket(AF_INET,SOCK_STREAM,0);
	if(0 > pasv_sock)
	{
		perror("socket");
		exit(EXIT_FAILURE);
	}

	svr_addr.sin_port = htons(port);
	if(connect(pasv_sock,(SP)&svr_addr,sizeof(svr_addr)))
	{
		perror("连接数据通道失败\n");
		exit(EXIT_FAILURE);
	}
	return pasv_sock;
}

//字符串输入 将回显代替为ch指定字符，ch为0正常显示，ch为' '不显示
char* input_password(char* key,int len,char ch)
{
    char ch1; 
    int i=0; 	//判断输入个数
    while(1)
    {
        ch1 = getch();  //每次输入单个字符，无回显 
        if(127 == ch1) //判断退格键
        {
            if(i>0)
            {
                i--;
                if(ch != ' ')
                	printf("\b \b");
                
            }
        }
        else if('\n' == ch1) //判断回车键
        {
            	printf("\n");
            	break; 
        }
        else if(i<len)  //判断字符个数是否小于20,密码个数不超过19个
        {
            key[i++]=ch1;
            
            if(ch == 0)
            {
            	printf("%c",ch1); //将所有密码显示为'*'
            }
            else if(ch != ' ')
            {
            	printf("%c",ch);
            }
            
        }
    }
    key[i]='\0';  //末尾添加结束标志'\0'
    return key;  //链式调用
}




