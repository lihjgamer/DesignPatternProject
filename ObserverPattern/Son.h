#pragma once
#include "BaseRole.h"
#include "ObserverMgr.h"
class CSon :
	public CBaseRole,
	public CObserverMgr
{
public:
	CSon(std::string name, int role, int age);
	~CSon();

	virtual void update(unsigned long timestamp);
};

