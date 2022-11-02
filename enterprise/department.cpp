#include <iostream>
#include <cstring>
#include "department.h"
#include "tools.h"
using namespace std;

Department::Department(void) {}

Department::Department(const char* name)
{
	strcpy(m_strName,name);
	m_iId = get_id("./data/deptid.dat");
}

Department::~Department(void)
{
	
}
//	修改部门编号
void Department::setId(int id)
{
	m_iId = id;
}

void Department::setName(char* name)
{
	strcpy(m_strName,name);
}

int Department::getId(void)
{
	return m_iId;
}

char* Department::getName(void)
{
	return m_strName;
}

ostream& operator<<(ostream& os,const Department& dpt)
{
	return os << "部门编号:" << dpt.m_iId << " 部门名称:" << dpt.m_strName << " 部门人数:" << dpt.empArr.size(); 
}

istream& operator>>(istream& is,Department& dpt)
{ 
	return is >> dpt.m_strName; 
}

