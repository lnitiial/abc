#ifndef TOOL_H
#define TOOL_H
extern char name[50][20]; 	// 姓名
extern char sex[50];		// 性别
extern char tel[50][12]; 	// 电话
extern int count;		// 有效联系人数量


int menu(void);
void msg_show(const char* msg,float sec);
void anykey_continue(void);


#endif //TOOL_H
