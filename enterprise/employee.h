#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
using namespace std;

class Employee
{
	int m_iId;
	int m_iAge;
	char m_strName[20];
	char m_cSex;
public:	
	Employee(void);
	Employee(const char* name,char sex,int age);
	void setId(int id);
	void setAge(int age);
	void setName(const char* name);
	void setSex(char sex);
	int getId(void);
	int getAge(void);
	char* getName(void);
	char getSex(void);
	
	//	运算符重载
	// << >>
	friend ostream& operator<<(ostream& os,const Employee& emp);

	friend istream& operator>>(istream& is,Employee& emp);


};


#endif//EMPLOYEE_H
