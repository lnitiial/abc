#ifndef CLI_TOOLS_H
#define CLI_TOOLS_H

#include "bank.h"

extern Customer cus;
extern Server ser;
extern int msqid;




int menu(void);
int menu_2(void);
void msg_snd_rcv(int miqid,long type,Customer* cus,Server* ser);
void anykey_continue(void);
char* input_password(char* key);
char* input_words(char* key,int len);
void msg_show(const char* msg,float sec);

#endif//CLI_TOOLS_H
