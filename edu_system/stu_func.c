#include <stdio.h>
#include <stdlib.h>
#include <getch.h>
#include <string.h>
#include "system.h"
#include "stu_func.h"
#include "all_tools.h"

//查询成绩
void query_score(int p)
{
	float max_score_chinese=0;//语文最高分
	float max_score_math=0;//数学最高分
	float max_score_english=0;//英语最高分
	float max_score_sum=0;//最高总分
	float min_score_chinese=100;//语文最低分
	float min_score_math=100;//数学最低分
	float min_score_english=100;//英语最低分
	float min_score_sum=300;//最低总分
	int rank=0;//自己的排名
	float avg_score_chinese=0;//语文平均分
	float avg_score_math=0;//数学平均分
	float avg_score_english=0;//英语平均分
	float score[MAX_STU];//算总分的排名
	float score_chinese[MAX_STU];//算语文的排名
	float score_math[MAX_STU];//算数学的排名
	float score_english[MAX_STU];//算英语的排名
	float sum_score=Stu[p].chinese+Stu[p].math+Stu[p].english;//当前学生的总成绩
	int sum_in_school=0;//当前在校人数
	printf("您的成绩语文：%3.1f 数学：%3.1f 英语：%3.1f 总分：%3.1f\n",Stu[p].chinese,Stu[p].math,Stu[p].english,sum_score);
	for(int i=0;i<Sum_stu;i++)
	{
		if(true == Stu[i].in_school)
		{
			score[sum_in_school]=Stu[i].chinese+Stu[i].math+Stu[i].english;//当前下标i学生的总分
			score_chinese[sum_in_school]=Stu[i].chinese;//当前下标i学生的语文
			score_math[sum_in_school]=Stu[i].math;//当前下标i学生的数学
			score_english[sum_in_school]=Stu[i].english;//当前下标i学生的英语
			sum_in_school++;
			if(max_score_chinese < Stu[i].chinese)
			{
				max_score_chinese = Stu[i].chinese;//语文最高分
			}
			else if(min_score_chinese > Stu[i].chinese)
			{
				min_score_chinese = Stu[i].chinese;//语文最低分
			}
		
		
			if(max_score_math < Stu[i].math)
			{
				max_score_math = Stu[i].math;//数学最高分
			}
			else if(min_score_math > Stu[i].math)
			{
				min_score_math = Stu[i].math;//数学最低分
			}
		
		
			if(max_score_english < Stu[i].english)
			{
				max_score_english = Stu[i].english;//英语最高分
			}
			else if(min_score_english > Stu[i].english)
			{
				min_score_english = Stu[i].english;//英语最低分
			}

			if(max_score_sum < Stu[i].chinese+Stu[i].math+Stu[i].english)
			{
				max_score_sum = Stu[i].chinese+Stu[i].math+Stu[i].english;//总分最高分
			}
			else if(min_score_sum > Stu[i].chinese+Stu[i].math+Stu[i].english)
			{
				min_score_sum = Stu[i].chinese+Stu[i].math+Stu[i].english;//总分最低分
			}
			if(sum_score < Stu[i].chinese+Stu[i].math+Stu[i].english)//排名
			{
				rank++;
			}
		
			avg_score_chinese=avg_score_chinese+Stu[i].chinese;//语文总分
			avg_score_math=avg_score_math+Stu[i].math;//数学总分
			avg_score_english=avg_score_english+Stu[i].english;//英语总分
		}
	}
	float temp;
	printf("*********************************************************************\n");
	//总分排名
	for(int i=0;i<sum_in_school;i++)
	{
		for(int j=sum_in_school-1;j>i;j--)
		{
			if(score[j-1]<score[j])
			{
				temp=score[j];
				score[j]=score[j-1];
				score[j-1]=temp;
			}
		}
	}
	//语文成绩排名
	for(int i=0;i<sum_in_school;i++)
	{
		for(int j=sum_in_school-1;j>i;j--)
		{
			if(score_chinese[j-1]<score_chinese[j])
			{
				temp=score_chinese[j];
				score_chinese[j]=score_chinese[j-1];
				score_chinese[j-1]=temp;
			}
		}
	}
	//数学成绩排名
	for(int i=0;i<sum_in_school;i++)
	{
		for(int j=sum_in_school-1;j>i;j--)
		{
			if(score_math[j-1]<score_math[j])
			{
				temp=score_math[j];
				score_math[j]=score_math[j-1];
				score_math[j-1]=temp;
			}
		}
	}
	//英语成绩排名
	for(int i=0;i<sum_in_school;i++)
	{
		for(int j=sum_in_school-1;j>i;j--)
		{
			if(score_english[j-1]<score_english[j])
			{
				temp=score_english[j];
				score_english[j]=score_english[j-1];
				score_english[j-1]=temp;
			}
		}
	}
	
	printf("总分和各科目排名的排名：\n");
	printf("总分   语文  数学 英语 \n");
	for(int i=0;i<sum_in_school;i++)//罗列各科成绩和总分的排名
	{
		printf("%5.1f %5.1f %5.1f %5.1f\n",score[i],score_chinese[i],score_math[i],score_english[i]);

	}
	printf("*********************************************************************\n");
	avg_score_chinese=avg_score_chinese/(double)sum_in_school;//语文平均分
	avg_score_math=avg_score_math/(double)sum_in_school;//数学平均分
	avg_score_english=avg_score_english/(double)sum_in_school;//英语平均分
	printf("语文最高分：%-5.1f 数学最高分：%-5.1f 英语最高分：%-5.1f 总分最高：%-5.1f\n",max_score_chinese,max_score_math,max_score_english,max_score_sum);
	printf("语文最低分：%-5.1f 数学最低分：%-5.1f 英语最低分：%-5.1f 总分最低：%-5.1f\n",min_score_chinese,min_score_math,min_score_english,min_score_sum);
	printf("语文平均分：%-5.1f 数学平均分：%-5.1f 英语平均分：%-5.1f 总平均分：%-5.1f\n",avg_score_chinese,avg_score_math,avg_score_english,avg_score_chinese+avg_score_math+avg_score_english);
	printf("您在班级中的排名位:%d\n",rank+1);
	anykey_continue();
}
//修改密码
void chang_pass(int p)
{
	char pass_change[20];//接受输入第一次密码
	char pass_change_ag[20];//接收第二次密码
	while(1)
	{
		printf("请输入要修改后的密码：（长度在3～20位之间）");
		input_password(pass_change);		//输入密码，且限制长度
		stdin->_IO_read_ptr = stdin->_IO_read_end;		//清空缓冲区
		printf("再次输入要修改后的密码：（长度在3～20位之间）");
		input_password(pass_change_ag);		//确定输入的密码，且限制长度
		if(0 == strcmp(pass_change,pass_change_ag) && 3<strlen(pass_change))//判断两次的输入的密码是否一致，且长度是否在限定范围内
		{
			strcpy(Stu[p].password,pass_change);		//新密码覆盖旧密码，完成修改
			msg_show("修改成功",1.5);
			return;
		}
		else
		{
			printf("两次输入不一致或密码长度过短！\n");
		}
	}
}	
//查看个人信息	
void query_infor(int p)
{
	printf("姓名：%s\t性别：%-6s学号：%8s\n",Stu[p].name,'w'==Stu[p].sex?"女":"男",Stu[p].id);
	anykey_continue();
}
