#ifndef PRI_FUNC_H
#define PRI_FUNC_H
#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__);
#else 
	#define debug(...)
#endif
void reset_pri(void);//重置校长密码

void reset_tea(void);//重置老师密码

void add_tea(void);//添加教师

void del_tea(void);//删除教师

void show_onjob(void);//显示在职教师

void show_quitjob(void);//显示离职教师

void unlock_tea(void);//解锁教师帐号

#endif//PRI_FUNC_H
