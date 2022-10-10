#ifndef TOOLS_H
#define TOOLS_H

#include <stdio.h>
#include <stdbool.h>


#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__);
#else 
	#define debug(...)
#endif

void show_view(void); //显示界面

bool if_die(void);	//判断是否死亡

void rand_two(void); //随机生成数字2

#endif //TOOLS_H
