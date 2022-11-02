#ifndef SERVICE_CTRL_H
#define SERVICE_CTRL_H

#include <vector>
#include "department.h"
#include "employee.h"
using namespace std;

class ServiceCtrl
{
public:
	virtual ~ServiceCtrl(void) {};
	virtual bool addDept(Department& dpt)=0;
	virtual int delDept(int id)=0;
	virtual vector<Department>& listDept(void)=0;
	virtual bool addEmp(int,Employee& emp)=0;
	virtual bool delEmp(int id)=0;
	virtual bool modEmp(int id,Employee& emp)=0;
	virtual Department* listEmp(int id)=0;
	virtual vector<Department>& listAllEmp(void)=0;

};

#endif//SERVICE_CTRL_H
