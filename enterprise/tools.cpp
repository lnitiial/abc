#include <iostream>
#include <mysql/mysql.h>
#include <getch.h>
#include <fstream>
#include "tools.h"
using namespace std;

void anykey_continue(void)
{
	cout << "按任意键继续..." << endl;
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	getch();
}

void msg_show(const char* msg,float sec)
{
	cout << msg << endl;
	fflush(stdout);
	usleep(sec*1000000);
}
//	生成唯一的管理员ID号。
int get_id(const char* path)
{
	int id;
	ifstream fin(path);
	if(!fin)
	{
		return -1;
	}
	fin >> id;
	fin.close();
	
	id++;
	ofstream fout(path);
	if(!fout)
	{
		return -1;
	}
	
	fout << id;
	
	return id;
}

char get_cmd(char start,char end)
{
	while(true)
	{
		
		char cmd = getch();
		if(cmd >= start && cmd <= end)
		{
			
			cout << cmd <<endl;
			return cmd;
		}
	}
}




		
