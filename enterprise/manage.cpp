#include <iostream>
#include <cstring>
#include "tools.h"
#include "manager.h"

Manager::Manager(void) {}

Manager::Manager(const char* name,const char* pwd) 
{
	strcpy(m_strName,name);
	strcpy(m_strPwd,pwd);
	m_iId = get_id("./data/mgrid.dat");
	
}

//	获取管理员ID
int Manager::getId(void)const
{
	return m_iId;
}
//	获取管理员姓名
const char* Manager::getName(void)const
{
	return m_strName;
}
//	获取管理员密码
const char* Manager::getPwd(void)const
{
	return m_strPwd;
}

//	设置管理员ID
void Manager::setId(int id)
{
	m_iId = id;
}
//	设置管理员姓名
void Manager::setName(const char* name)
{
	strcpy(m_strName,name);
}
//	设置管理员密码
void Manager::setPwd(const char* pwd)
{
	strcpy(m_strPwd,pwd);
}
