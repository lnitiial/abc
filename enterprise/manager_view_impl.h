#ifndef MANAGER_VIEW_IMPL_H
#define MANAGER_VIEW_IMPL_H

#include "manager_view.h"
#include "service_view.h"
#include "manager_ctrl.h"

class ManagerViewImpl : public ManagerView
{

	ManagerCtrl* mgrCtrl;
	ServiceView* srcView;
public:
	ManagerViewImpl(void);
	~ManagerViewImpl(void);
	void loginManager(void);
	void loginService(void);
	void menuMgr(void);
	void addMgr(void);
	void delMgr(void);
	void listMgr(void);
	void sysmenu(void);
	void start(void);
};


#endif//MANAGER_VIEW_IMPL_H
