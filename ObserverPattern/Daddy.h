#pragma once
#include "BaseRole.h"
#include "Observer.h"
class CDaddy :
	public CBaseRole,
	public CObserver
{
public:
	CDaddy(std::string name, int role, int age);
	~CDaddy();

	virtual void update(unsigned long timestamp);

	virtual void notify() ;


};

