#ifndef MANAGER_MODE_H
#define MANAGER_MODE_H

#include <vector>
#include "manager.h"

class ManagerMode
{
public:
	virtual void load(std::vector<Manager>& vmgr)=0;
	virtual void save(std::vector<Manager>& vmgr)=0;
};

#endif//MANAGER_MODE_H
