#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdbool.h>
#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__);
#else 
	#define debug(...)
#endif

//函数声明
//**************************************
void init_system(void);//初始化系统函数
void start_system(void);//运行系统函数
void end_system(void);//结束系统函数
//**************************************

//**************************************
//学生文件：student.txt
//教师文件：teacher.txt
//校长文件: principal.txt
//导入学生基础信息文件：stu_inf.txt
//导入学生成绩文件：score
//**************************************


//宏定义
//**************************************
#define MAX_TEA 50	//所有教师教师人数最大值（离校教师+在校教师）
#define MAX_STU 500	//所有学生人数最大值（离校学生+在校学生）
#define MAX_PRI 1	//校长人数最大值
#define PRI_INIT_PASS "12345" //校长密码初始化
#define TEA_INIT_PASS "1234" //教师密码初始化
#define STU_INIT_PASS "123" //学生密码初始化
#define CHI_SCO_MAX 100	//语文满分成绩
#define MAT_SCO_MAX 100 //数学满分成绩
#define ENG_SCO_MAX 100 //英语满分成绩
//**************************************


//结构体定义
//***************************************************************
typedef struct Student//学生结构体
{
	char name[20];//名字
	char password[20];//密码 
	float chinese;//语文成绩
	float math;//数学成绩
	float english;//英语成绩
	char sex;//性别
	bool in_school;//是否在校状态
	bool cur_state;//当前状态是不是被锁定 false为锁定 true为自由状态
	bool is_first;//是否是第一次登录 ture为第一次登录
	char id[9];//学号

}Student;

typedef struct Teacher//教师结构体
{
	char password[20];//密码 初始化为1234
	char name[20];//名字
	char id[9];//工号
	bool cur_state;//当前状态 false为锁定 true为自由状态
	bool is_first;//是否是第一次登录  ture为第一次登录
	bool in_school;//是否在校状态
	char sex;//性别
}Teacher;

typedef struct Principal//校长专属结构体
{
	bool is_first;//是否是第一次登录  ture为第一次登录
	char password[20];//密码 
}Principal;
//****************************************************************



//全局变量声明
//****************************************************************
extern Student *Stu;//在校和离校学生

extern int Sum_stu; //总学生数量

extern Teacher *Tea;//在校老师

extern int Sum_tea;//总教师数量

extern Principal *Pri;//校长
//****************************************************************

#endif//SYSTEM_H
