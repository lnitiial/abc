#ifndef BANK_H
#define BANK_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <getch.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>


typedef struct Account
{
	char account_nub[9];	//账号 8位
	char identity_card[20];		//身份证号	18位
	char password[20];	//	密码最多19位
	double money;		//	账户金额
	bool lock_state;	//	锁定状态
	
}Account;

typedef struct Customer
{
	long mtype;		//	消息类型
	Account acct;	//	账户信息
	pid_t pid;		//	进程pid

}Customer;

typedef struct Server
{
	long mtype;		//	消息类型
	char tip[256];	//	提示信息
	
}Server;


#endif//BANK_H
