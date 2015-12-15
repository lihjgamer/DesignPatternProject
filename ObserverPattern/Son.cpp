#include "Son.h"


CSon::CSon(std::string name, int role, int age)
:CBaseRole(name,role,age)
{
}


CSon::~CSon()
{
}

void CSon::update(unsigned long timestamp)
{
	CObserver* pobserver = nullptr;
	for (std::list<CObserver*>::iterator iter = m_list_observer.begin();
		iter != m_list_observer.end();
		++ iter)
	{
		pobserver = (*iter);
		pobserver->notify();
	}
}
