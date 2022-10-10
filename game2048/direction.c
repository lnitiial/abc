#include "direction.h"
#include "tools.h"
#include "game2048.h"
//上
void up(void)
{
	//debug("%s\n",__func__);

	for(int i=0;i<4;i++)
	{
		int flag = 0;
		for(int j=1;j<4;j++)
		{
			if(p[j][i]!=0)
			{
				if(p[flag][i]==0)
				{
					p[flag][i]=p[j][i];
					p[j][i]=0;
					is_move_merge = true;
				}
				else if(p[j][i]==p[flag][i])
				{
					p[flag][i]+=p[j][i];
					p[j][i]=0;
					is_move_merge = true;
					flag++;
				}
				else
				{
					p[flag+1][i]=p[j][i];
					if(flag+1!=j)
					{
						p[j][i]=0;	
					}
					flag++;
				}
			}
			
		}
	}
} 
//下
void down(void)	
{
	//debug("%s\n",__func__);
	for(int i=0;i<4;i++)
	{
		int flag = 3;
		for(int j=2;j>=0;j--)
		{
			if(p[j][i]!=0)
			{
				if(p[flag][i]==0)
				{
					p[flag][i]=p[j][i];
					p[j][i]=0;
					is_move_merge = true;
				}
				else if(p[j][i]==p[flag][i])
				{
					p[flag][i]+=p[j][i];
					p[j][i]=0;
					flag--;
					is_move_merge = true;
				}
				else
				{
					p[flag-1][i]=p[j][i];
					if(flag-1!=j)
					{
						p[j][i]=0;	
					}
					flag--;
				}
			}
			
		}
	}

}

//左
void left(void)	
{
	//debug("%s\n",__func__);
	for(int i=0;i<4;i++)
	{
		int flag = 0;
		for(int j=1;j<4;j++)
		{
			if(p[i][j]!=0)
			{
				if(p[i][flag]==0)
				{
					p[i][flag]=p[i][j];
					p[i][j]=0;
					is_move_merge = true;
				}
				else if(p[i][j]==p[i][flag])
				{
					p[i][flag]+=p[i][j];
					p[i][j]=0;
					flag++;
					is_move_merge = true;
				}
				else
				{
					p[i][flag+1]=p[i][j];
					if(flag+1!=j)
					{
						p[i][j]=0;	
					}
					flag++;
				}
			}
			
		}
	}

}

//右
void right(void)
{
	//debug("%s\n",__func__);
	for(int i=0;i<4;i++)
	{
		int flag = 3;
		for(int j=2;j>=0;j--)
		{
			if(p[i][j]!=0)
			{
				if(p[i][flag]==0)
				{
					p[i][flag]=p[i][j];
					p[i][j]=0;
					is_move_merge = true;
				}
				else if(p[i][j]==p[i][flag])
				{
					p[i][flag]+=p[i][j];
					p[i][j]=0;
					is_move_merge = true;
					flag--;
				}
				else
				{
					p[i][flag-1]=p[i][j];
					if(flag-1!=j)
					{
						p[i][j]=0;	
					}
					flag--;
				}
			}
			
		}
	}


}
