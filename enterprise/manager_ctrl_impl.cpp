#include <iostream>
#include "manager_ctrl_impl.h"
#include "manager_mode_impl.h"
using namespace std;

ManagerCtrlImpl::ManagerCtrlImpl(void)
{

	mgrMode = new ManagerModeImpl;
	mgrMode->load(mgrArr);
}


ManagerCtrlImpl::~ManagerCtrlImpl(void)
{
	mgrMode->save(mgrArr);
	delete mgrMode;
}


bool ManagerCtrlImpl::addMgr(Manager& mgr)
{
	mgrArr.push_back(mgr);
	return true;
}

bool ManagerCtrlImpl::delMgr(int id)
{
	vector<Manager>::iterator it;
	for(it=mgrArr.begin(); it!= mgrArr.end(); it++)
	{   
		if(id == it->getId())
		{
			mgrArr.erase(it); 
			return true; 
		}
		
	}  
	return false;
	
}
vector<Manager>& ManagerCtrlImpl::listMgr(void)
{
	
	vector<Manager>::iterator it;
	for(it=mgrArr.begin(); it!= mgrArr.end(); it++)
	{   
		cout << "ID号：" << it->getId() << " 用户名："  << it->getName() << " 密码：" << it->getPwd() << endl;
	}  	
	return mgrArr;
	
}
