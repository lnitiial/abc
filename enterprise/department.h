#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <iostream>
#include <vector>
#include "employee.h"

using namespace std;

class Department
{
	int m_iId;
	char m_strName[20];
public:
	std::vector<Employee> empArr;
	Department(void);
	Department(const char* name);
	~Department(void);
	void setId(int id);
	void setName(char* name);
	int getId(void);
	char* getName(void);

	//运算符重载
	//<< >>
	
	friend ostream& operator<<(ostream& os,const Department& dpt);
	
	friend istream& operator>>(istream& is,Department& dpt);

	
};


#endif//DEPARTMENT_H
