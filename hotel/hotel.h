#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>

#define ID_MAX (19)
#define Single_Room (1)		//	单人房
#define Standard_Room (2)	//	标间
#define	Deluxe_Room	(3)		//	豪华间


//	旅客类
class Guest
{
    char* name;					// 	旅客姓名
    char  sex;					//	旅客性别
    char* id;					//	旅客身份证
public:
   Guest(char* name,char sex,char* id);
   ~Guest();
   void show(void);				//	显示旅客信息 
};

//	房间类
class Room					
{   
    int nub; 					//	房间号	
    int type;					//	房间类型(决定人数上限)
    int price;					//	房价
    int occupy;	   				//	入住人数			
    Guest** guest;				//	旅客数组
public:
	
	
    Room(int nub,int type,int price);
    ~Room();
    bool check_in(char* name,char sex,char* id);		//	入住
    void check_out(void);		//	退房
    void show(void);			//	显示房间信息
    int room_nub(void);
    int room_occupy(void);
    int room_type(void);

};

//	酒店类
class Hotel
{
    int layer;					//	层数
    int* each_num;				//	每层房间数
    Room*** room;				//	房间对象
    static Hotel hotel;			//	饿汉模式
    Hotel();
    Hotel(const Hotel& that);
public:
    ~Hotel();
    static Hotel& get_hotel(void);	//	获取类对象
    int auto_find(int num);		//	自动查询满足人数的房间号
    void check_in(int nub,char* name,char sex,char* id);		//	入住
    void check_out(int nub);		//	退房
    void show_empty(void);			//	查看空房
    void show_room(int nub);		//	查看房间
    void upgrade(int nub);				//	升级房间
    int menu(void);					//	菜单
    
};



#endif//HOTEL_H
