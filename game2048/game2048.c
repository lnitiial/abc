#include <stdlib.h>
#include <getch.h>
#include "game2048.h"
#include "direction.h"
#include "tools.h"

int score = 0;
int (*p)[4] =NULL;
bool is_move_merge = true;
//判断是否产生移动 合并的标志

// 初始化相关数据、加载数据
void init_game(void)
{
	//debug("%s\n",__func__);
	//申请堆内存
	p=malloc(sizeof(p[0][0])*4*4);
	//初始化数据
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			p[i][j]=0;
		}
	}
	
	//读取文件,加载数据
}

// 运行游戏
void start_game(void)
{
	//debug("%s\n",__func__);
	for(;;)
	{
		//	随机位置生成2
		rand_two();
		
		is_move_merge = false;
		
		//	显示界面
		show_view();
		//	检查是否还能继续
		if(if_die())
		{
			printf("GAME OVER!\n");
			return;
		}	
		//	获取放向键并处理
		switch(getch())
		{
			case 183:	up();	 break;
			case 184:	down();	 break;
			case 186:	left();  break;
			case 185:	right(); break;
		}
		
	}
}
// 释放相关资源、保存数据
void end_game(void)
{
	//debug("%s\n",__func__);
	//保存数据
		
	//释放内存
	free(p);
	p=NULL;
}
