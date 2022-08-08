#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <getch.h>
#include "tea_func.h"
#include "teacher.h"
#include "system.h"
#include "all_tools.h"

//添加学生
void tea_add(void)
{
	//debug("%s\n",__func__);
	if(MAX_STU <= Sum_stu) 		 // 判断是否满员
	{
		msg_show("系统正在升级,请等待...",1.5);
		return;
	}
	puts("请选择添加方式:");
	puts("1、手动添加");
	puts("2、批量添加");
	char cmd = getch();
	printf("%c\n",cmd);	
	switch(cmd)
	{
		//手动添加信息
		case '1':
		{
			single_add(); //单独添加
			msg_show("添加联系人成功!\n",1.5);
		
		}
		break;
		//批量添加信息
		case '2':
		{
			batch_add();//批量添加
		}
		break;
	}	 
}

//删除学生
void tea_del(void)
{
	//debug("%s\n",__func__);
	
	char key[9]={};//第一次输入的学号
	char key_ag[9]={};//第二次输入的学号
	printf("请输入你要删除的学生学号：");
	input_words(key,8);//输入学号号，并限制学号号长度
	stdin->_IO_read_ptr = stdin->_IO_read_end;//清空缓冲区
	for(int i=0;i<Sum_stu;i++)
	{
		if(true == Stu[i].in_school)
		{
			if(0 == strcmp(Stu[i].id,key)) 
			{
				printf("请再次输入需要删除的学生学号:");
				input_words(key_ag,8);//输入学号，并限制学号长度
				if(0 == strcmp(key,key_ag))
				{
					Stu[i].in_school = false; //改变学生在校状态为离校
					msg_show("删除学生成功\n",1.5);
				}
				else
				{
					msg_show("两次学号不一致,删除失败\n",1.5);	
				}
				
				return;
			}
		}

	}
	msg_show("查无此人,删除失败!\n",1.5);
}

//查找学生
void tea_find(void)
{
	//debug("%s\n",__func__);
	char key[9] = {};
	printf("请输入需要查找的学生学号:");
	input_words(key,8);		//输入学号，并限制学号长度
	stdin->_IO_read_ptr = stdin->_IO_read_end;		//清空缓冲区
	for(int i=0;i<Sum_stu;i++)  	//遍历总学生信息中在校学生部分
	{
		if(true == Stu[i].in_school)
		{
			if(0 == strcmp(key,Stu[i].id) )   //同时判断字符串和学号是否相等
			{
				printf("姓名：%s\t性别：%-6s学号：%8s 语文:%-5.1f 数学:%-5.1f 英语%-5.1f\n",Stu[i].name,'w'==Stu[i].sex?"女":"男",Stu[i].id,Stu[i].chinese,Stu[i].math,Stu[i].english); 
				anykey_continue();
				return;
			}
		}

	}
	
	msg_show("查无此人!\n",1.5);
	
}

//修改学生信息
void tea_mod(void) 
{
	//debug("%s\n",__func__);
	char key[9] = {};
	printf("请输入需要修改的学生学号:");
	input_words(key,8);
	for(int i=0;i<Sum_stu;i++)
	{
		if(Stu[i].in_school)
		{
			if(0 == strcmp(key,Stu[i].id))
			{
				printf("姓名:%s\t性别:%-6s学号:%8s 语文:%-5.1f 数学:%-5.1f 英语%-5.1f\n",Stu[i].name,'w'==Stu[i].sex?"女":"男",Stu[i].id,Stu[i].chinese,Stu[i].math,Stu[i].english); 
				puts("请选择需要修改的内容");
				puts("1、修改学生基础信息");
				puts("2、修改学生成绩");
				stdin->_IO_read_ptr = stdin->_IO_read_end; 		//输入字符串再输入单个字符前先清空缓冲区
				char cmd = getch();
				printf("%c\n",cmd);	// 回显
				switch(cmd)
				{	
					case '1':
					{
						printf("请输入需要修改学生的姓名:");
						MyFgets(Stu[i].name,20);
						stdin->_IO_read_ptr = stdin->_IO_read_end;//清空缓冲区
						printf("请输入需要修改学生的性别(w/m):");
						scanf(" %c",&Stu[i].sex);
						stdin->_IO_read_ptr = stdin->_IO_read_end;//清空缓冲区
						while('w' != Stu[i].sex && 'm' != Stu[i].sex)
						{
							printf("性别格式输入错误！请重新输入：");
							scanf("%c",&Stu[i].sex);
						}
					}
					break;
					case '2':
					{
						printf("请输入需要修改的语文、数学、英语成绩");
						scanf("%f%f%f",&Stu[i].chinese,&Stu[i].math,&Stu[i].english);
						while(0>Stu[i].chinese || CHI_SCO_MAX<Stu[i].chinese)
						{
							Stu[i].chinese=-1;
							printf("输入语文的成绩有误!\n");
							printf("请重新输入语文成绩：");
							scanf("%f",&Stu[i].chinese);
						}
						while(0>Stu[i].math || MAT_SCO_MAX<Stu[i].math)
						{
							Stu[i].math=-1;
							printf("输入数学的成绩有误!\n");
							printf("请重新输入数学成绩：");
							scanf("%f",&Stu[i].math);
						}
						while(0>Stu[i].english || ENG_SCO_MAX<Stu[i].english)
						{
							Stu[i].english=-1;
							printf("输入英语的成绩有误!\n");
							printf("请重新输入英语成绩：");
							scanf("%f",&Stu[i].english);
						}
						anykey_continue();
					}
					break;
				}
				msg_show("修改信息成功!\n",1.5);
				return;
							
			}
		}

	}
	msg_show("查无此人,修改失败!\n",1.5);
}

//录入学生成绩 
void tea_input(void)	
{
	//debug("%s\n",__func__);
	puts("请选择导入方式:");
	puts("1、手动录入");
	puts("2、批量导入");

	char cmd = getch();
	printf("%c\n",cmd);	
	switch(cmd)
	{
		case '1':
		{
			single_input();//手动录入
			
		}
		break;
		case '2':
		{
			batch_input();//批量导入
		}
		break;
	}
	
}

//重置密码
void tea_reset_stu(void)
{
	debug("%s\n",__func__);
	char reset_id[9];	//接受输入学号的数组
	printf("请输入要重置的学生的学号：");
	input_words(reset_id,8);		//输入学号，并限制学号长度
	for(int i=0; i<Sum_stu;i++)
	{
		if(true == Stu[i].in_school && 0 == strcmp(reset_id,Stu[i].id)) //按学号查找学生
		{
			strcpy(Stu[i].password,STU_INIT_PASS);		//将学生密码初始化
			Stu[i].is_first=true; 	//重置密码后将其状态改为第一次登录，使其登录强制修改密码
			msg_show("重置密码成功!\n",1.5);
			return;
		}
	}
	msg_show("未找到该学生！\n",1.5);
}

//显示所有在校学生信息
void tea_display_school(void)
{
	debug("%s\n",__func__);
	for(int i=0; i<Sum_stu;i++) //遍历所有学生信息中在校学生部分
	{
		if(Stu[i].in_school)
		{
			printf("姓名：%s\t性别：%-6s学号：%8s 语文:%-5.1f 数学:%-5.1f 英语%-5.1f\n",Stu[i].name,'w'==Stu[i].sex?"女":"男",Stu[i].id,Stu[i].chinese,Stu[i].math,Stu[i].english); 
		}
	}
	anykey_continue();
}

//显示所有退学学生信息 
void tea_display_drop(void) 
{
	debug("%s\n",__func__);
	for(int i=0; i<Sum_stu;i++)  //遍历所有学生信息中离校学生部分
	{
		if(false == Stu[i].in_school)
		{
			printf("姓名：%s\t性别：%-6s学号：%8s\n",Stu[i].name,'w'==Stu[i].sex?"女":"男",Stu[i].id);	
		}
	}
	anykey_continue();
}

//解锁帐号
void tea_unlock(void)
{
	debug("%s\n",__func__);
	char key[9] = {};
	printf("请输入需要解锁的学生学号:");
	input_words(key,8);
	for(int i=0;i<Sum_stu;i++)
	{
		if(Stu[i].in_school)
		{
			if(0 == strcmp(key,Stu[i].id)) //按学号查找
			{
				if(false == Stu[i].cur_state)
				{
					Stu[i].cur_state = true;   //将学生状态该为自由状态
					msg_show("解锁成功!\n",1.5);
					return;
				}
				else
				{
					msg_show("该学生未锁定!\n",1.5);
					return;
				}
			}
		}

	}
	msg_show("未找到该学生!\n",1.5);
}

//批量添加
void batch_add(void)
{
	debug("%s\n",__func__);
	// 打开需要批量添加学生信息的文件
	int cnt=0; //统计成功导入数据个数
	char path[20]={};
	printf("请输入需要导入的文件路径:");
	input_words(path,19);
	FILE* frp = fopen(path,"r");
	if(NULL == frp)
	{
		msg_show("文件不存在\n",1.5);
		return;
	}
	int i=0; 
	// 以文本方式读取文件内容（学生信息格式：姓名 性别(m/w)）每行存储一个学生信息
	while(-1 != fscanf(frp,"%s %c\n",Stu[Sum_stu+i].name,&Stu[Sum_stu+i].sex))  //fscanf未读取到数据返回-1
	{
		//添加每一个学生信息时，自动生成学号，初始化密码，初始化其各个状态 
		generate_num(Stu[Sum_stu+i].id,"2019",Sum_stu+1+i,4);    
		Stu[Sum_stu+i].in_school = true;
		Stu[Sum_stu+i].cur_state = true;
		Stu[Sum_stu+i].is_first = true;
		strcpy(Stu[Sum_stu+i].password,STU_INIT_PASS);
		i++; 
		cnt++;
	}
	//跳出循环后 i 的值为读取到的学生信息条数，总学生信息数改变
	Sum_stu+=i;
	fclose(frp);
	printf("成功添加%d条数据",cnt);
	msg_show("批量导入成功!\n",1.5);
}

//单个添加
void single_add(void)
{
	debug("%s\n",__func__);
	//在尾部添加基础信息
	printf("请输入新学生的姓名:");
	MyFgets(Stu[Sum_stu].name,20);
	stdin->_IO_read_ptr = stdin->_IO_read_end;//清空缓冲区
	printf("请输入新学生的性别(w\m):");
	scanf("%c",&Stu[Sum_stu].sex);
	stdin->_IO_read_ptr = stdin->_IO_read_end;//清空缓冲区
	while('w' != Stu[Sum_stu].sex && 'm' != Stu[Sum_stu].sex)
	{
		printf("性别格式输入错误！请重新输入：");
		scanf("%c",&Stu[Sum_stu].sex);
	}
	//自动生成学号、初始化在校状态、首次登录、锁定状态
	generate_num(Stu[Sum_stu].id,"2019",Sum_stu+1,4);// 学号自动生成 格式 20190001
	Stu[Sum_stu].in_school = true;	//在校状态
	Stu[Sum_stu].cur_state = true; 	//自由状态
	Stu[Sum_stu].is_first = true;	//第一次登录
	strcpy(Stu[Sum_stu].password,STU_INIT_PASS); //密码初始化123

	Sum_stu++;
}

//批量录入
void batch_input(void) 
{
	int cnt=0; //统计成功导入数据个数
	int cnt1=0; //统计总数据条数
	debug("%s\n",__func__);
	char path[20]={};
	char id_sign[9]; //存储每次读取到的学号信息
	float score_chinese = 0,score_math=0,score_english=0; //存储每次读取到的语文、数学、英语成绩信息
	//以文本方式打开需要批量导入成绩的文件(格式：学号 语文 数学 英语) 
	printf("请输入需要导入的文件路径(格式：学号 语文 数学 英语) ：");
	input_words(path,19);
	FILE* frp = fopen(path,"r");
	if(NULL == frp)
	{
		msg_show("文件不存在\n",1.5);
		return;
	}
	while(-1 != fscanf(frp,"%s %f %f %f\n",id_sign,&score_chinese,&score_math,&score_english))
	{
		int i=0;
		for(i=0;i<MAX_STU;i++)
		{
			if(Stu[i].in_school)
			{
				if(0 == strcmp(Stu[i].id,id_sign) && (0<score_chinese && CHI_SCO_MAX>score_chinese) && (0<score_math && MAT_SCO_MAX>score_math) && (0<score_english && ENG_SCO_MAX>score_english))//成绩有效时才会输入
				{
					Stu[i].chinese = score_chinese;
					Stu[i].math = score_math;
					Stu[i].english = score_english;
					cnt++;
					break;
				}
			}

		}
		if(MAX_STU == i)		//说明未找到对应学生或者成绩无效
		{
			printf("文件中第%d行数据导入失败\n",cnt1+1);		//返回导入失败的文件行数
		}
		cnt1++;
		
	}
	printf("------------------------------\n");
	printf("成功导入%d条数据,%d条数据导入失败\n",cnt,cnt1-cnt);
	anykey_continue();
}
//单个录入
void single_input(void)
{
	debug("%s\n",__func__);
	char key[9]={};
	printf("请输入需要导入成绩的学生学号:");
	input_words(key,8);
	for(int i=0;i<Sum_stu;i++)
	{
		if(Stu[i].in_school)
		{
			if(0 == strcmp(key,Stu[i].id))
			{		
				printf("请输入需要修改的语文、数学、英语成绩");
				scanf("%f%f%f",&Stu[i].chinese,&Stu[i].math,&Stu[i].english);
				while(0>Stu[i].chinese || CHI_SCO_MAX<Stu[i].chinese)
				{
					Stu[i].chinese=-1;
					printf("输入语文的成绩有误!\n");
					printf("请重新输入语文成绩：");
					scanf("%f",&Stu[i].chinese);
				}
				while(0>Stu[i].math || MAT_SCO_MAX<Stu[i].math)
				{
					Stu[i].math=-1;
					printf("输入数学的成绩有误!\n");
					printf("请重新输入数学成绩：");
					scanf("%f",&Stu[i].math);
				}
				while(0>Stu[i].english || ENG_SCO_MAX<Stu[i].english)
				{
					Stu[i].english=-1;
					printf("输入英语的成绩有误!\n");
					printf("请重新输入英语成绩：");
					scanf("%f",&Stu[i].english);
				}
				msg_show("导入成绩成功!\n",1.5);
				anykey_continue();
				return;		
			}
		}

	}
	msg_show("输入的学号不正确！\n",1.5);
}


