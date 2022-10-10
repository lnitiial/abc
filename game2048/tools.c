#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "game2048.h"
#include "tools.h"



// 判断是否满
static bool is_full(void)
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(p[i][j]==0)
				return false;
		}	
	}
	return true;
}

//显示界面
void show_view(void)
{
	//debug("%s\n",__func__);
	system("clear");
	for(int i=0;i<4;i++)
	{
		printf("---------------------\n");
		for(int j=0;j<4;j++)
		{
			if(p[i][j])
				printf("|%4d",p[i][j]);
			else
				printf("|    ");
		}
		printf("|\n");
	}
	printf("---------------------\n");
}

//随机生成数字2
void rand_two(void)
{
	
	//debug("%s\n",__func__);
	//判断是否有空位置
	
	                                                
	if(is_full()==0 && is_move_merge)
	{
		int x=0,y=0;
		srand(time(NULL));
		x=rand()%4;
		y=rand()%4;
		while(p[x][y]!=0)
		{
			x=rand()%4;
			y=rand()%4;		
		}
		p[x][y]=2;
	}
	return;
}

//判断是否死亡
bool if_die(void)
{
	//debug("%s\n",__func__);
	if(is_full()==0)
		return false;
	//判断横向
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(p[i][j] == p[i][j+1])
				return false;
		}
	}
	//判断纵向
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(p[i][j] == p[i+1][j])
				return false;
		}

	}
	
	return true;
}


