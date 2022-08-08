#ifndef STU_FUNC_H
#define STU_FUNC_H
#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__);
#else 
	#define debug(...)
#endif
void query_score(int p);//查询成绩

void chang_pass(int p);//修改密码

void query_infor(int p);//查看个人信息	

#endif//STU_FUNC_H
