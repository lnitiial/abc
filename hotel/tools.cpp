#include <iostream>
#include <cstdlib>
#include <getch.h>
#include "tools.h"
using namespace std;


void msg_show(const char* msg,float sec)
{
	cout << msg << endl;
	fflush(stdout);
	usleep(sec*1000000);
}


void anykey_continue(void)
{
	cout << "按任意键继续..." << endl;
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	getch();
}
