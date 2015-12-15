#pragma once
#include <list>
class CObserver;
class CObserverMgr
{
public:
	CObserverMgr();
	virtual ~CObserverMgr();

	void register_observer(CObserver* pobserver);
	void unregister_observer(CObserver* pobserver);
	void unregister_observer(int index);
	void unregister_all_observer();

protected:
	std::list<CObserver*>  m_list_observer;

};

