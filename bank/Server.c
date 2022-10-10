#include "bank.h"

pid_t pid[9]={};

//	捕获信号
void sigint(int num)
{
	for(int i=0;i<9;i++)
	{
		printf("杀死子进程:%u\n",pid[i]);
		kill(pid[i],9);	
	}
}

//	启动子进程
const char* path[9] = {
	"./bin/open",
	"./bin/destory",
	"./bin/login",
	"./bin/unlock",
	"./bin/save",
	"./bin/take",
	"./bin/transfer",
	"./bin/query",
	"./bin/modify"
};


int main(int argc,const char* argv[])
{
	signal(SIGINT,sigint);
	//	创建消息队列
	int msqid = msgget(ftok(".",666),IPC_CREAT|0644);
	if(0 >msqid)
	{
		perror("msgget");	
		return -1;
	}
	for(int i=0; i<9; i++)
	{
		pid[i] = vfork();
		if(0 == pid[i])
		{
			execl(path[i],path[i],NULL);
		}
		
	}
	

	
	while(-1 == wait(NULL));
	msgctl(msqid,IPC_RMID,NULL);
	printf("服务器关闭成功!\n");
}

