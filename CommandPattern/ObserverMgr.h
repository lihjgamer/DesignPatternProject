#pragma once
#include <list>

/*
	�� ���۲��� �� �۲����� �ϲ�
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
	
	// notify ����ֵ ���ڿ��� �Ƿ����֪ͨ���� �۲���
	virtual bool notify(void* pvoid = nullptr) { return true; }

protected:
	std::list<CObserverMgr*>  m_list_observer;

};

