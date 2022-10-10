#ifndef FTP_CLI_H
#define FTP_CLI_H

typedef struct sockaddr* SP;

extern struct sockaddr_in svr_addr;
extern char addr_ip[16];
extern char buf[4096];
extern size_t buf_size;

int connect_to_server(const char* ip);

void user_login(int socket);

void pwd_command(int sockfd);

void mkdir_command(int sockfd,char* par);

void rmdir_command(int sockfd,char* par);

void cd_command(int sockfd,char* par);

void ls_command(int sockfd,char* par);

void put_command(int sockfd,char*par);

void get_command(int sockfd,char* par);

void bye_command(int sockfd);

#endif//FTP_CLI_H
