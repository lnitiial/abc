#include <iostream>
#include "manager_view_impl.h"
#include "manager_ctrl_impl.h"
#include "service_view_impl.h"
#include "manager.h"
#include "tools.h" 
using namespace std;

ManagerViewImpl::ManagerViewImpl(void)
{
	mgrCtrl = new ManagerCtrlImpl;
	srcView = new ServiceViewImpl;
}



ManagerViewImpl::~ManagerViewImpl(void)
{
	 delete mgrCtrl;
	 delete srcView;
}

void ManagerViewImpl::loginManager(void)
{
	for(;;)
	{
		menuMgr();
		switch(get_cmd('1','4'))
		{
			case '1': addMgr();		break;
			case '2': delMgr();		break;
			case '3': listMgr(); 	break;
			case '4': return;
		}
	
	}
	
}

void ManagerViewImpl::loginService(void)
{
	for(;;)
	{
		srcView->menuSrc();
		switch(get_cmd('1','9'))
		{
			case '1': srcView->addDept();		break;
			case '2': srcView->delDept();		break;
			case '3': srcView->listDept();		break;
			case '4': srcView->addEmp();		break;
			case '5': srcView->delEmp(); 		break;
			case '6': srcView->modEmp(); 		break;
			case '7': srcView->listEmp(); 		break;
			case '8': srcView->listAllEmp(); 	break;
			case '9': return;
		}
	
	}
}

void ManagerViewImpl::menuMgr(void)
{
	system("clear");
	cout << "****欢迎使用管理子系统****" << endl;
	cout << "1、添加业务管理员" << endl;
	cout << "2、删除业务管理员" << endl;
	cout << "3、列出所有管理员" << endl;
	cout << "4、退出管理子系统 " << endl;
	cout << "**************************" << endl;
	cout << "请输入指令:";

}

void ManagerViewImpl::addMgr(void)
{
	
	cout << "请输入管理员的用户名和密码：";
	char name[20];
	char pwd[20];
	cin >> name >> pwd;
	//	有参构造生成一个管理员
	Manager mgr;
	mgr.setName(name);
	mgr.setPwd(pwd);
	
	if(mgrCtrl->addMgr(mgr))
	{
		msg_show("创建成功！",1.5);
	}
	else
	{
		msg_show("创建失败！",1.5);
	}
	
	
}

void ManagerViewImpl::delMgr(void)
{
	cout << "请输入需要删除的管理员的ID号:";
	int id;
	cin >> id;
	if(mgrCtrl->delMgr(id))
	{
		msg_show("删除成功！",1.5);
	}
	else
	{
		msg_show("删除失败！",1.5);
	}
	
	
	
}

void ManagerViewImpl::listMgr(void)
{
	mgrCtrl->listMgr();
	anykey_continue();

}

void ManagerViewImpl::sysmenu(void)
{
	system("clear");
	cout << "****欢迎使用企业信息管理系统****" << endl;
	cout << "1、管理子系统" << endl;
	cout << "2、业务子系统" << endl;
	cout << "3、退出系统" << endl;
	cout << "********************************" << endl;
	cout << "请输入指令:";
}
void ManagerViewImpl::start(void)
{

	for(;;)
	{
		sysmenu();
		switch(get_cmd('1','3'))
		{
			case '1': loginManager();		break;
			case '2': loginService();		break;
			case '3': return;
		}
	
	}
}





