#include <fstream>
#include "service_mode_impl.h"
#include "department.h"
#include "employee.h"


void ServiceModeImpt::load(vector<Department>& dptArr)
{
	ifstream fin("./data/services.dat");
	if(!fin)
	{
		return;
	}
	int id;
	char name[20];
	int size;
	char sex;
	int age;
	while(true) 
	{
		fin >> id >> name >> size;
		if(fin.fail()) break;
		Department  dpt;
		dpt.setId(id);
		dpt.setName(name);
		for(int i=0; i<size; i++)
		{
			fin >> id  >> name >> sex >> age;
			Employee emp;
			emp.setId(id);
			emp.setName(name);
			emp.setSex(sex);
			emp.setAge(age);
			dpt.empArr.push_back(emp);
		}
		dptArr.push_back(dpt);
		
	}
	fin.close();
}

void ServiceModeImpt::save(vector<Department>& dptArr)
{
	ofstream fout("./data/services.dat");
	if(!fout)
	{
		return;
	}
	for(int i=0; i<dptArr.size(); i++)
	{
		fout << dptArr[i].getId() << " " << dptArr[i].getName() << " " << dptArr[i].empArr.size() << endl;
		for(int j=0; j<dptArr[i].empArr.size(); j++)
		{
			fout << dptArr[i].empArr[j].getId() << " " << dptArr[i].empArr[j].getName() << " " << dptArr[i].empArr[j].getSex() << " " << dptArr[i].empArr[j].getAge() << endl;
		}
	}
	fout.close();
	
}
