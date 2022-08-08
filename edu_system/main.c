#include <stdio.h>
#include "system.h"

int main(int agc,const char* argv[])
{
	init_system();//初始化系统
	start_system();//运行系统
	end_system();//结束系统
}
