#include <stdio.h>
#include <getch.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <network.h>
char *MyFgets(char data[],int count);

void* run(void* arg)
{
	char buf[4096] = {};
	size_t buf_size = sizeof(buf);
	for(;;)	
	{
		int ret = recv_nw(arg,buf,buf_size);
		if(0 >= ret)
		break;
		printf("\b\b\b%s\n",buf);
		printf(">>>");
		fflush(stdout);
	}
	return NULL;
}


int main(int argc,const char* argv[])
{
	//	创建socket、准备地址、绑定、监听
	NetWork* snw = init_nw(SOCK_STREAM,5566,"127.0.0.1",false);	
	if(NULL == snw)
	{
		perror("init_nw");	
		return EXIT_FAILURE;
	}
	char name[20] = {};
	printf("请输入昵称：");
	MyFgets(name,20);
	int ret = send_nw(snw,name,strlen(name)+1);
	if(0 >= ret)  
	{
		perror("send_nw");
		return EXIT_FAILURE;
	}
	
	
	//	开辟子线程接收数据
	pthread_t tid;

	pthread_create(&tid,NULL,run,snw);
	
	char buf[4096] = {};
	size_t buf_size = sizeof(buf);
	//	主进程发送数据
	for(;;)
	{
		printf(">>>");
		MyFgets(buf,buf_size);
		if(0 == strcmp(buf,"quit"))
		{
			return EXIT_SUCCESS;
		}
		int ret = send_nw(snw,buf,strlen(buf)+1);
		if(0 >= ret) 
		{
			perror("send_nw");
			return EXIT_FAILURE;
		}
	}
	pthread_join(tid,NULL);
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

