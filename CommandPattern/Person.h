#pragma once


#include <queue>
#include "Command.h"
#include "ObserverMgr.h"

class CPerson : public CObserverMgr
{
public:
	CPerson();
	virtual ~CPerson();

	int get_id();


	virtual void do_bake() {}

	virtual void do_take_order() {}

	virtual void recieve_cmd(){}
	virtual void send_cmd(){}


	void push(CCommand* pCommand)
	{
		m_list.push_front(pCommand);
	}

	void erase()
	{
		m_list.pop_back();
	}

	CCommand* get_first()
	{
		CCommand* pCommand = m_list.back();
		m_list.pop_back();
		return pCommand;
	}

	int get_msg_count();
	

protected:
	int m_id;

	std::list<CCommand*> m_list;

};

class CBaker;
class CCustomer;
class CWaiter;
//////////////////////////////////////////////////////////////////////////
// 烤面包师
class CBaker : 
	public CPerson
{
public :
	CBaker();
	~CBaker();

	void set_waiter(CWaiter* pWaiter);
	void do_bake();

	void active();
private:
	CWaiter* m_pWaiter;

	int m_max_msg_count;
};
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 消费者
class CCustomer :
	public CPerson
{
public:
	CCustomer();
	~CCustomer();

	void do_take_order();
	bool notify(void* pvoid);

	void set_waiter(CWaiter* pWaiter);
private:
	CWaiter* m_pWaiter;
};

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 服务员

class CWaiter :
	public CPerson
{
public:
	CWaiter();
	~CWaiter();
	void execute(void* pvoid);

	bool notify(void* pvoid);

};
//////////////////////////////////////////////////////////////////////////