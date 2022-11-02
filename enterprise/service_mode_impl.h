#ifndef SERVICE_MODE_IMPL_H
#define SERVICE_MODE_IMPL_H

#include "service_mode.h"
#include "department.h"
#include "employee.h"

class ServiceModeImpt : public ServiceMode
{
public:
	void load(vector<Department>& dptArr);
	void save(vector<Department>& dptArr);
};

#endif//SERVICE_MODE_IMPL_H
