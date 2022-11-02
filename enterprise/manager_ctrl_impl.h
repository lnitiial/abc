#ifndef MANAGER_CTRL_IMPL_H
#define MANAGER_CTRL_IMPL_H

#include "manager_ctrl.h"
#include "manager_mode.h"
#include "manager.h"


class ManagerCtrlImpl : public ManagerCtrl
{
	std::vector<Manager> mgrArr;
	ManagerMode* mgrMode;
	
public:
	
	ManagerCtrlImpl(void);
	~ManagerCtrlImpl(void);
	
	bool addMgr(Manager& mgr);
	bool delMgr(int id);
	std::vector<Manager>& listMgr(void);
	
};


#endif//MANAGER_CTRL_IMPL_H
