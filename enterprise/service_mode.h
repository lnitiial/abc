#ifndef SERVICE_MODE_H
#define SERVICE_MODE_H

#include <vector>
#include "department.h"
using namespace std;

class ServiceMode
{
public:
	virtual void load(vector<Department>& dptArr)=0;
	virtual void save(vector<Department>& dptArr)=0;
};


#endif//SERVICE_MODE_H
