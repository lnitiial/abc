#include "service_ctrl_impl.h"
#include "service_mode_impl.h"

ServiceCtrlImpl::ServiceCtrlImpl(void)
{
	srcMode = new ServiceModeImpt;
	srcMode->load(deptArr);
}


ServiceCtrlImpl::~ServiceCtrlImpl(void)
{
	srcMode->save(deptArr);
	delete srcMode;
	
}

bool ServiceCtrlImpl::addDept(Department& dpt)
{
	deptArr.push_back(dpt);
	return true;
}

int ServiceCtrlImpl::delDept(int id)
{
	vector<Department>::iterator it;
	for(it=deptArr.begin(); it!= deptArr.end(); it++)
	{   
		if(id == it->getId())
		{
			deptArr.erase(it); 
			return true; 
		}
		
	}  
	return false;
}

vector<Department>& ServiceCtrlImpl::listDept(void)
{
	vector<Department>::iterator it;
	for(it=deptArr.begin(); it!= deptArr.end(); it++)
	{   
		cout << *it << endl;
	}  
	return deptArr;
}

bool ServiceCtrlImpl::addEmp(int id,Employee& emp)
{
	vector<Department>::iterator it;
	for(it=deptArr.begin(); it!= deptArr.end(); it++)
	{   
		if(id == it->getId())
		{
			it->empArr.push_back(emp);
			return true;
		}
	}  
	return false;
}

bool ServiceCtrlImpl::delEmp(int id)
{
	vector<Department>::iterator it;
	for(it=deptArr.begin(); it!= deptArr.end(); it++)
	{   
		vector<Employee>::iterator jt;
		for(jt=it->empArr.begin(); jt!=it->empArr.end(); jt++)
		{
			if(id == jt->getId())
			{
				it->empArr.erase(jt);
				return true;
			}
		}
	}  
	return false;
}

bool ServiceCtrlImpl::modEmp(int id,Employee& emp)
{
	vector<Department>::iterator it;
	for(it=deptArr.begin(); it!= deptArr.end(); it++)
	{   
		vector<Employee>::iterator jt;
		for(jt=it->empArr.begin(); jt!=it->empArr.end(); jt++)
		{
			if(id == jt->getId())
			{
				jt->setName(emp.getName());
				jt->setSex(emp.getSex());
				jt->setAge(emp.getAge());
				return true;
			}
		}
	}  
	return false;
}

Department* ServiceCtrlImpl::listEmp(int id)
{
	vector<Department>::iterator it;
	for(it=deptArr.begin(); it!= deptArr.end(); it++)
	{   
		if(id == it->getId())
		{
			cout << "-------------------------------------" << endl;
			cout << *it << endl;
			cout << "-------------------------------------" << endl;
			vector<Employee>::iterator jt;
			for(jt=it->empArr.begin(); jt!=it->empArr.end(); jt++)
			{
				cout << *jt << endl;
			}
			return &(*it);
		}
	}  
	return NULL;
}

vector<Department>& ServiceCtrlImpl::listAllEmp(void)
{
	vector<Department>::iterator it;
	cout << "-------------------------------------" << endl;
	for(it=deptArr.begin(); it!= deptArr.end(); it++)
	{   
		vector<Employee>::iterator jt;
		for(jt=it->empArr.begin(); jt!=it->empArr.end(); jt++)
		{
			cout << *jt << endl;
		}
	}  
	return deptArr;
}

