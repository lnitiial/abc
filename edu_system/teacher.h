#ifndef TEACHER_H
#define TEACHER_H
#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__);
#else 
	#define debug(...)
#endif
void enter_tea(void);//进入教师页面

#endif//TEACHER_H
