#ifndef ALL_TOOLS_H
#define ALL_TOOLS_H

void anykey_continue(void);//按任意键继续

void msg_show(const char* msg,float sec);//显示提示信息延时

char* input_password(char* key);//密码回显

char* input_words(char* key,int len);////带数目限制功能的输入函数

char *MyFgets(char data[],int count); //fgets输入姓名函数，且功能能去除末尾的\n

char* generate_num(char *id,const char* prefix,int suffix,int suf_num);//编号生成 id为输出字符串, prefix前缀 suffix后缀 suf_num后缀长度 前缀可以是字符串,后缀是整形数据,位数不足在前补0



int stu_menu(void);	//打印学生界面

int tea_menu(void);	//打印教师界面

int pri_menu(void);	//打印校长界面



int is_enter_stu(void);//判断是否能进入学生界面

int is_enter_tea(void);//判断是否能进入教师界面

int is_enter_pri(void);//判断校长是否能进入校长界面

#endif//ALL_TOOLS_H
