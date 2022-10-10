#include <iostream>
#include <getch.h>
#include "hotel.h"
#include "tools.h"
using namespace std;

Hotel Hotel::hotel;

int main(int argc,const char* argv[])
{
	Hotel& htl = Hotel::get_hotel();

	for(;;)
	{
		// 显示主界面	
		switch(htl.menu())
		{
			case '1':	
			{
				int nub,num;
				char sex;
			 	char name[20];
				char id[ID_MAX];
				cout << "请输入住房人数："<< endl;
				cin >> num;
				cout << "请选择(1、手动入住/2、自动入住)";
				stdin->_IO_read_ptr = stdin->_IO_read_end;
				switch(getch())
				{
					case '1':
					{
						cout << endl;
						cout << "请输入入住房号："<< endl;
						cin >> nub;
						for(int i=0; i<num; i++)
						{
							cout << "请输入身份信息(姓名、性别、身份证号)：";
							cin >> name >> sex >> id;
							htl.check_in(nub,name,sex,id);
						}
						msg_show("办理成功!",1.5);
					}break;
					case '2':
					{
						nub = htl.auto_find(num);
						cout << endl;
						for(int i=0; i<num; i++)
						{
							cout << "请输入身份信息(姓名、性别、身份证号)：";
							cin >> name >> sex >> id;
							htl.check_in(nub,name,sex,id);
						}
						cout << "您的房号是" << nub << endl;
						msg_show("办理成功!",2.0);
						
					}break;
				
				}
				
				
				
			}break;
			case '2':	
			{
				int nub = 0;
				cout << "请输入待退房房间号：";
				cin >> nub;
				htl.check_out(nub);break;
			}
			case '3':	htl.show_empty();break;
			case '4':	
			{
				int nub = 0;
				cout << "请输入查询房间号：";
				cin >> nub;
				htl.show_room(nub);
			}break;
			case '5':	
			{
				int nub = 0;
				cout << "请输入待升级的房间号：";
				cin >> nub;
				htl.upgrade(nub);
			}break;
			case '6':	
			{
				return 0;
			}
		}


	}
	
}
