#include <iostream>
#include <cstdlib>
#include <cstring>
#include <getch.h>
#include "tools.h"
#include "hotel.h"
using namespace std;


//	旅客
Guest::Guest(char* name,char sex,char* id):sex(sex)
{
	this->name = new char[strlen(name)+1];
	strcpy(this->name,name);
	this->id = new char[ID_MAX];
	strcpy(this->id,id);
}
Guest::~Guest()
{
	delete[] name;
	delete[] id;
}
//	显示旅客信息 
void Guest::show(void)
{
	string str = 'm' == sex? "男":"女";
	cout << "姓名: " << name << " 性别：" << str << " 身份证号：" << id << endl; 	
}


//	房间
Room::Room(int nub,int type,int price):nub(nub),type(type),price(price)
{
	occupy = 0;
	guest = new Guest*[this->type];
}
Room::~Room()
{
	check_out();
	delete guest;
}
//	入住
bool Room::check_in(char* name,char sex,char* id)	
{
	//	判断房间是否已满
	if(occupy < type)
	{
		guest[occupy++] = new Guest(name,sex,id);		
		return true;
	}
	return false;
}
//	退房		
void Room::check_out(void)		
{
	for(int i=0; i<occupy; i++)
	{
		delete guest[i];	
	}
	occupy = 0;
}
//	显示房间信息		
void Room::show(void)
{
	const char* arr[] = {"单人间","标间","豪华套房"};
	if(0 != occupy)
	{
		for(int i=0; i<occupy; i++)
		{
			cout << "房间号：" << nub << " 房型：" << arr[type-1] << " 房价(元/天)：" << price << endl;
			cout << "--------------------------------------------" << endl;
			guest[i]->show();	
		}
	}
	else
	{
		cout << "房间号：" << nub << " 房型：" << arr[type-1]<< " 房价(元/天)：" << price << endl;
		
	}
	
}
int Room::room_nub(void)
{
	return nub;
}

int Room::room_occupy(void)
{
	return occupy;
}

int Room::room_type(void)
{
	return type;
}
			


//	酒店
Hotel::Hotel()
{
	FILE* frp = fopen("hotel.txt","r");
	if(NULL == frp)
	{
		perror("frp");
		exit(0);
	}
	//	读取层数
	fscanf(frp,"%d\n",&layer);
	//	创建每层房间数组
	each_num = new int[layer];
	room = new Room**[layer];
	int i=0;
	for(i=0; i<layer; i++)
	{
		fscanf(frp,"%d\n",each_num+i);
		room[i] = new Room*[each_num[i]];
		for(int j=0; j<each_num[i]; j++)
		{
			//	读取文件中的房间信息并进行有参构造
			int nub,type,price;
			fscanf(frp,"%d %d %d\n",&nub,&type,&price);
			room[i][j] = new Room(nub,type,price);					
		}
	}
	fclose(frp);

}
Hotel& Hotel::get_hotel(void)	//	获取类对象
{
	return hotel;
}

Hotel::Hotel(const Hotel& that)
{
	//	单例模式下无拷贝构造
}

Hotel::~Hotel()
{
	//	将所有房客退房
	int i=0;
	for(i=0; i<layer; i++)
	{
		for(int j=0; j<each_num[i]; j++)
		{
			if(0 != room[i][j]->room_occupy())
			{
				room[i][j]->check_out();	
			}
			
		}
	}
	
	for(i=0; i<layer; i++)
	{
		for(int j=0; j<each_num[i]; j++)
		{
			delete room[i][j];
		}
		delete[] room[i];
	}
	delete[] room;
	delete[] each_num;
	
}
int Hotel::auto_find(int num)
{
	int i=0;
	for(i=0; i<layer; i++)
	{
		for(int j=0; j<each_num[i]; j++)
		{
			if(num == room[i][j]->room_type())
			{
				return room[i][j]->room_nub();			
			}
		}
	}
	
	for(i=0; i<layer; i++)
	{
		for(int j=0; j<each_num[i]; j++)
		{
			if(num < room[i][j]->room_type())
			{
				return room[i][j]->room_nub();			
			}
		}
	}
	return -1;

}


//	入住
void Hotel::check_in(int nub,char* name,char sex,char* id)
{
	int i=0;
	for(i=0; i<layer; i++)
	{
		for(int j=0; j<each_num[i]; j++)
		{
			if(nub == room[i][j]->room_nub())
			{
				room[i][j]->check_in(name,sex,id);
				msg_show("入住成功!",0.5);
				return;			
			}
		}
	}
	msg_show("入住失败!",1.5);
	
}
//	退房		
void Hotel::check_out(int nub)
{
	int i=0;
	for(i=0; i<layer; i++)
	{
		for(int j=0; j<each_num[i]; j++)
		{
			if(nub == room[i][j]->room_nub())
			{
				room[i][j]->check_out();
				msg_show("退房成功!",1.5);
				return;			
			}
		}
	}
	msg_show("退房失败!",1.5);
	
}
//	查看空房	
void Hotel::show_empty(void)
{
	
	int i=0;
	for(i=0; i<layer; i++)
	{
		printf("第%d层：\n",i);
		for(int j=0; j<each_num[i]; j++)
		{
			if(0 == room[i][j]->room_occupy())
			{
				cout << "   ";
				room[i][j]->show();
			}
		}
		cout << endl;
	}
	anykey_continue();
	
}
//	查看房间	
void Hotel::show_room(int nub)
{	
	int i=0;
	for(i=0; i<layer; i++)
	{
		for(int j=0; j<each_num[i]; j++)
		{
			if(nub == room[i][j]->room_nub())
			{
				if(0 != room[i][j]->room_occupy())
				{
					
					room[i][j]->show();
					anykey_continue();
				}
				else
				{
					room[i][j]->show();
					cout << "--------------------------------------------" << endl;
					cout << "该房间为空" << endl;
					anykey_continue();
				}
				return;
				
			}
		}
	}
	msg_show("查无此房!",1.5);
}
//	升级房间	
void Hotel::upgrade(int num)
{
	
}

int Hotel::menu(void)
{
	system("clear");
	cout << "****欢迎ikun酒店管理系统****" << endl;
	cout << "1、办理入住" << endl;
	cout << "2、申请退房" << endl;
	cout << "3、查看空房" << endl;
	cout << "4、查询房间" << endl;
	cout << "5、升级套房" << endl;
	cout << "6、退出系统" << endl;
	cout << "*************************" << endl;
	cout << "请输入指令:";
	char cmd = getch();
	cout << cmd <<endl;
	return cmd;
}
			




