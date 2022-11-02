#ifndef MANAGER_MODE_IMPL_H
#define MANAGER_MODE_IMPL_H

#include "manager_mode.h"

class ManagerModeImpl : public ManagerMode
{

public:
	void load(std::vector<Manager>& vmgr);
	void save(std::vector<Manager>& vmgr);
};

#endif//MANAGER_MODE_IMPL_H
