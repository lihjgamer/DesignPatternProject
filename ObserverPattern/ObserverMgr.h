#pragma once
#include <list>
class CObserver;

/*
	被观察者 基类
*/
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

