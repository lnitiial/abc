#ifndef TOOLS_H
#define TOOLS_H

#include <stdlib.h>

int recv_cmd(int sockfd,char* buf,size_t len);

char *MyFgets(char data[],int count);

int PASV_cmd(int sockfd);

char* input_password(char* key,int len,char ch);

#endif//TOOLS_H
