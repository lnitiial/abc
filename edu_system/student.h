#ifndef STUDENT_H
#define STUDENT_H
#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__);
#else 
	#define debug(...)
#endif
void enter_stu(void);//进入学生页面

#endif//STUDENT_H
