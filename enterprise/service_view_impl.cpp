#include <iostream>
#include "department.h"
#include "employee.h"
#include "service_view_impl.h"
#include "service_ctrl_impl.h"
#include "tools.h"
using namespace std;


ServiceViewImpl::ServiceViewImpl(void)
{
	srcCtrl = new ServiceCtrlImpl; 
}

ServiceViewImpl::~ServiceViewImpl(void)
{
	delete srcCtrl;

}

void ServiceViewImpl::menuSrc(void)
{
	system("clear");
	cout << "****欢迎使用业务子系统****" << endl;
	cout << "1、添加企业部门" << endl;
	cout << "2、删除企业部门" << endl;
	cout << "3、列出部门信息" << endl;
	cout << "4、增加部门员工 " << endl;
	cout << "5、删除部门员工" << endl;
	cout << "6、修改员工信息" << endl;
	cout << "7、生成员工列表" << endl;
	cout << "8、列出全体员工" << endl;
	cout << "9、退出业务系统" << endl;
	cout << "**************************" << endl;
	cout << "请输入指令:";
}
void ServiceViewImpl::addDept(void)
{
	char name[20];
	cout << "请输入新的部门名称：" ;
	cin >> name;
	Department dept;
	dept.setName(name);
	if(srcCtrl->addDept(dept))
	{
		msg_show("创建成功！",1.5);
	}
	else
	{
		msg_show("创建失败！",1.5);
	}

}

void ServiceViewImpl::delDept(void)
{
	int id;
	cout << "请输入待删除部门ID号：" ;
	cin >> id;
	if(srcCtrl->delDept(id))
	{
		msg_show("删除成功！",1.5);
	}
	else
	{
		msg_show("删除失败！",1.5);
	}
}

void ServiceViewImpl::listDept(void)
{
	srcCtrl->listDept();
	anykey_continue();
}

void ServiceViewImpl::addEmp(void)
{
	char name[20];
	char sex;
	int age;
	int id;
	cout << "请输入新员工的姓名、性别、年龄、部门ID：" ;
	cin >> name >> sex >> age >> id;	
	Employee emp;
	emp.setName(name);
	emp.setSex(sex);
	emp.setAge(age);
	if(srcCtrl->addEmp(id,emp))
	{
		msg_show("添加成功！",1.5);
	}
	else
	{
		msg_show("添加失败！",1.5);
	}

}



void ServiceViewImpl::delEmp(void)
{
	int id;
	cout << "请输入待删除员工ID号：" ;
	cin >> id;
	
	if(srcCtrl->delEmp(id))
	{
		msg_show("删除成功！",1.5);
	}
	else
	{
		msg_show("删除失败！",1.5);
	}
}

void ServiceViewImpl::modEmp(void)
{
	char name[20];
	char sex;
	int age;
	int id;
	cout << "请输入待修改员工ID号：" ;
	cin >> id;
	cout << "请输入修改后的姓名、性别、年龄：" ;
	cin >> name >> sex >> age;
	Employee emp;
	emp.setName(name);
	emp.setSex(sex);
	emp.setAge(age);
	if(srcCtrl->modEmp(id,emp))
	{
		msg_show("修改成功！",1.5);
	}
	else
	{
		msg_show("修改失败！",1.5);
	}
}

void ServiceViewImpl::listEmp(void)
{
	int id;
	cout << "请输入部门的ID号：" ;
	cin >> id;
	if(NULL == srcCtrl->listEmp(id))
	{
		cout << "未找到该部门！" << endl;
	}
	anykey_continue();
	
}

void ServiceViewImpl::listAllEmp(void)
{
	srcCtrl->listAllEmp();
	anykey_continue();
}

