#include <stdio.h>
#include <stdlib.h>
#include <getch.h>
#include <string.h>
#include <stdbool.h>
#include "system.h"
#include "teacher.h"
#include "principal.h"
#include "student.h"

//第一次登陆的学生密码：123
//第一次登录的教师密码：1234
//第一次登录的校长密码：12345


//teacher.txt//所有在校教师信息
//student.txt//所有在校学生信息
//pricipal.txt//校长信息

Student *Stu = NULL; 		//在校学生
int Sum_stu=0;				//总学生数

Teacher *Tea=NULL;			//在校老师
int Sum_tea=0;				//总教师数

Principal *Pri = NULL; 		//校长


//初始化系统函数，将文本中的内容读取到数组中
void init_system(void)
{

	int ret=0;
	debug("%s\n",__func__);
	
	//读取全部学生文件
	Stu = calloc(sizeof(Student),MAX_STU);//为学生数组申请内存
	FILE *frp_stu=fopen("student.txt","r");//打开学生文件
	if(NULL == frp_stu)
	{
		perror("fopen");		//提示错误
		return;
	}
	while((ret = fread(Stu+Sum_stu,sizeof(Student),1,frp_stu))) //将学生文件中的信息读到Stu数组中
	{
		
		Sum_stu++;//总学生人数
		
	}
	fclose(frp_stu);//关闭学生文件
	frp_stu=NULL;//指针置空
	

	//读取全部教师文件
	Tea = calloc(sizeof(Teacher),MAX_TEA);//为教师数组申请内存
	FILE *frp_tea=fopen("teacher.txt","r");//打开教师文件
	if(NULL == frp_tea)
	{
		perror("fopen");		//提示错误
		return;
	}
	while((ret = fread(Tea+Sum_tea,sizeof(Teacher),1,frp_tea))) //将教师文件中的信息读Tea数组中
	{
		Sum_tea++;//总教师数
		
	}
	fclose(frp_tea);//关闭教师文件
	frp_tea=NULL;//指针置空
	
	//读取校长信息
	Pri=malloc(sizeof(Principal));//为校长指针申请堆内存
	Pri->is_first=true;//校长的第一次登录初始化
	strcpy(Pri->password,PRI_INIT_PASS);//校长第一次登录密码初始化为“PRI_INIT_PASS”
	
	
	FILE *frp_pri=fopen("principal.txt","r");//打开principal.txt文件
	if(NULL == frp_pri)
	{
		perror("fopen");		//提示错误
		return;
	}
	fread(Pri,sizeof(Principal),1,frp_pri);//读取principal.txt文件中校长的信息
	fclose(frp_pri);//关闭校长文件
	frp_pri=NULL;//指针置空
	
}
//运行主界面系统函数
void start_system(void)
{
	debug("%s\n",__func__);
	char ch;
	for(;;)
	{
		system("clear");
		printf("-----------------------------\n");
		printf("|          教务系统         |\n");
		printf("|---------------------------|\n");
		printf("|   1.学 生 登 录	    |\n");
		printf("|   2.教 师 登 录	    |\n");
		printf("|   3.校 长 登 录	    |\n");
		printf("|   q.退 出 教 务 系 统     |\n");
		printf("-----------------------------\n");
		printf("请选择登录方式:");
		ch=getch();
		printf("%c\n",ch);
		switch(ch)
		{
			case '1':enter_stu();break;
			case '2':enter_tea();break;
			case '3':enter_pri();break;
			case 'q':return;	
		}
		
	}

}
//结束系统函数
void end_system(void)
{
	//保存所有学生数据
	FILE* fwp_stu = fopen("student.txt","w");
	if(NULL == fwp_stu)
	{
		perror("fopen");		//提示错误
		return;
	}
	for(int i=0;i<Sum_stu;i++)
	{
		fwrite(Stu+i,sizeof(Student),1,fwp_stu);
	}
	fclose(fwp_stu);//关闭学生文件
	fwp_stu=NULL;//指针置空
	
	//保存校长的数据
	FILE *fwp_pri=fopen("principal.txt","w");
	if(NULL == fwp_pri)
	{
		perror("fopen");		//提示错误
		return;
	}
	fwrite(Pri,sizeof(Principal),1,fwp_pri);
	fclose(fwp_pri);//关闭校长文件
	fwp_pri=NULL;//指针置空
	
	//保存所有教师的数据
	FILE *fwp_tea=fopen("teacher.txt","w");
	for(int i=0;i<Sum_tea;i++)
	{
		fwrite(Tea+i,sizeof(Teacher),1,fwp_tea);
	}
	fclose(fwp_tea);//关闭教师文件
	fwp_tea=NULL;//指针置空
	
	//printf("%s\n",__func__);
	//释放内存
	free(Stu);
	free(Tea);
	free(Pri);
	//指针地址置空
	Tea=NULL;
	Pri=NULL;
	Stu=NULL;
	
}


