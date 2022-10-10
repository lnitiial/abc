#ifndef SUB_H
#define SUB_H
extern char name[50][20]; 	// 姓名
extern char sex[50];		// 性别
extern char tel[50][12]; 	// 电话
extern int count;		// 有效联系人数量

void add(void);
void del(void);
void mod(void);
void find(void);
void show(void);


#endif //SUB_H
