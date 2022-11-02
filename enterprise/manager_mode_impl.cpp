#include <fstream> 
#include "manager_mode_impl.h"
#include "manager.h" 

using namespace std;


void ManagerModeImpl::load(std::vector<Manager>& vmgr)
{
	ifstream fin("./data/managers.dat",ios::binary);
	if(!fin)
	{
		return;
	}
	
	Manager mgr("","");
	
	while(true) 
	{
		fin.read((char*)&mgr,sizeof(Manager));
		if(fin.fail()) break;
		vmgr.push_back(mgr);
		
	}
	fin.close();
}

void ManagerModeImpl::save(std::vector<Manager>& vmgr)
{
	ofstream fout("./data/managers.dat",ios::binary);
	if(!fout)
	{
		return;
	}

	for(int i=0; i<vmgr.size(); i++)
	{
		fout.write((char*)&vmgr[i],sizeof(Manager));
	}
	
	
	fout.close();
	
}
