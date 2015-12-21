#pragma once
#include <list>

/*
	将 被观察者 和 观察者类 合并
*/
class CObserverMgr
{
public:
	CObserverMgr();
	virtual ~CObserverMgr();

	void register_observer(CObserverMgr* pobserver);
	void unregister_observer(CObserverMgr* pobserver);
	void unregister_observer(int index);
	void unregister_all_observer();


	virtual void execute(void* pvoid);
	
	// notify 返回值 用于控制 是否继续通知其他 观察者
	virtual bool notify(void* pvoid = nullptr) { return true; }

protected:
	std::list<CObserverMgr*>  m_list_observer;

};

