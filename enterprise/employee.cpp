#include <iostream>
#include <cstring>
#include "employee.h"
#include "tools.h"

Employee::Employee(void) {}

Employee::Employee(const char* name,char sex,int age):m_cSex(sex),m_iAge(age)
{
	strcpy(m_strName,name);
	m_iId = get_id("./data/empid.dat");
}

//	修改ID
void Employee::setId(int id)
{
	m_iId = id;
}
//修改年龄
void Employee::setAge(int age)
{
	m_iAge = age;
}
//	修改姓名
void Employee::setName(const char* name)
{
	strcpy(m_strName,name);
}
//	修改性别
void Employee::setSex(char sex)
{
	m_cSex = sex;	
}

int Employee::getId(void)
{
	return m_iId;
}

int Employee::getAge(void)
{
	return m_iAge;
}

char* Employee::getName(void)
{
	return m_strName;
}

char Employee::getSex(void)
{
	return m_cSex;
}

ostream& operator<<(ostream& os,const Employee& emp)
{
	const char* sex;
	emp.m_cSex? sex = "男": sex="女";
	//os << "员工ID:" << emp.m_iId << " 姓名:" << emp.m_strName << " 性别:" << sex << " 年龄:" << emp.m_iAge; 
	os << "员工ID:" << emp.m_iId << " 姓名:" << emp.m_strName << " 性别:" << emp.m_cSex << " 年龄:" << emp.m_iAge; 
}

istream& operator>>(istream& is,Employee& emp)
{
	is >> emp.m_iId >> emp.m_strName >> emp.m_cSex  >> emp.m_iAge; 
}



