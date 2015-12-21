#include "ObserverMgr.h"

CObserverMgr::CObserverMgr()
{
	m_list_observer.clear();
}


CObserverMgr::~CObserverMgr()
{
	
}

void CObserverMgr::register_observer(CObserverMgr* pobserver)
{
	m_list_observer.push_back(pobserver);
}

void CObserverMgr::unregister_observer(CObserverMgr* pobserver)
{
	m_list_observer.remove(pobserver);
}

void CObserverMgr::unregister_observer(int index)
{
	int ndistance = 0;
	std::list<CObserverMgr*>::iterator itr = m_list_observer.begin();
	for (std::list<CObserverMgr*>::iterator iter = itr;
		iter != m_list_observer.end();
		++ iter)
	{
		 ndistance = std::distance(iter, itr);
		 if (ndistance == index)
		 {
			 m_list_observer.erase(iter);
			 break;
		 }
	}
}

void CObserverMgr::unregister_all_observer()
{
	m_list_observer.clear();
}

void CObserverMgr::execute(void* pvoid)
{
	CObserverMgr* pObserverMgr = NULL;
	for (std::list<CObserverMgr*>::iterator iter = m_list_observer.begin();
		iter != m_list_observer.end();
		++iter)
	{
		pObserverMgr = (*iter);
		if (!pObserverMgr->notify(pvoid))
		{
			break;
		}
	}
}


