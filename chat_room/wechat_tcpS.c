#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <network.h>
#include "threadpool.h"

//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

typedef struct Client
{
	NetWork* cnw;	//	存储sockfd
	char name[20];	//	存储客户端姓名
}Client;

Client cli[50];

//	群发函数 除client的所有人
void client_send(Client* client,char* buf)
{
	//	加锁
	//pthread_mutex_lock(&mutex);
	for(int i=0; i<50; i++)
	{
		if(cli[i].cnw && cli[i].cnw != client->cnw)
		{
			send_nw(cli[i].cnw,buf,strlen(buf)+1);
		}	
	}
	//	解锁
	//pthread_mutex_unlock(&mutex);
} 


void task(void* data)
{
	Client* client = (Client*)data;
	char buf[4096] = {};	//	接受到的消息
	char send[4096] ={};	//	发送的消息
	size_t buf_size = sizeof(buf);
	
	//	接收姓名
	recv_nw(client->cnw,client->name,20);
	//	转发消息
	sprintf(send,"\n欢迎%s进入聊天室!",client->name);
	client_send(client,send);
	
	for(;;)
	{
		int ret = recv_nw(client->cnw,buf,buf_size);
		if(0 >= ret || 0 == strcmp(buf,"quit"))
		{
				
			sprintf(send,"\n%s退出聊天室!",client->name);
			client_send(client,send);
			client->cnw = NULL;
			return;
			
		}
		printf("recv[%s]:%s bits%d\n",client->name,buf,ret);
	
		sprintf(send,"[%s]:%s",client->name,buf);
			
		client_send(client,send);
	}
}


int main(int argc,const char* argv[])
{
	//	创建socket、准备地址、绑定、监听
	NetWork* snw = init_nw(SOCK_STREAM,5566,"127.0.0.1",true);	
	if(NULL == snw)
	{
		perror("init_nw");	
		return EXIT_FAILURE;
	}
	ThreadPool* threadpool = create_threadpool(50,10,task);
	start_threadpool(threadpool);
	
	for(;;)
	{
		int index = 0;
		while(cli[index].cnw) index++;

		cli[index].cnw = accept_nw(snw);	
		if(cli[index].cnw == NULL)
		{
			perror("accept_nw");
			continue;
		}
		push_threadpool(threadpool,cli+index);		//	将客户端结构体入库
		
	}

}
