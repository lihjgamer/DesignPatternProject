#include "Person.h"
#include <random>
#include "Command.h"

int g_id_creator = 1;

CPerson::CPerson()
{
	m_id = g_id_creator ++;
}


CPerson::~CPerson()
{
}

int CPerson::get_id()
{
	return m_id;
}

int CPerson::get_msg_count()
{
	return m_list.size();
}

//////////////////////////////////////////////////////////////////////////
CBaker::CBaker()
{
	m_pWaiter = NULL;
	m_max_msg_count = 3;
}

CBaker::~CBaker()
{

}

void CBaker::do_bake()
{
	if (get_msg_count() <= 0)
	{
		return;
	}
	CCommand* pCommand = get_first();
	pCommand->To(m_id);
	execute(pCommand);
}

void CBaker::set_waiter(CWaiter* pWaiter)
{
	m_pWaiter = pWaiter;
}

void CBaker::active()
{
	CCommand* pCommand = NULL;
	int msg_count = m_max_msg_count - get_msg_count();
	int waiter_msg_count = m_pWaiter->get_msg_count();
	if (msg_count > 0 && waiter_msg_count > 0)
	{
		msg_count = msg_count > waiter_msg_count ? waiter_msg_count : msg_count;
		for (int i = 0; i < msg_count; i ++)
		{
			push(m_pWaiter->get_first());
		}
	}

	do_bake();
}

//////////////////////////////////////////////////////////////////////////

CCustomer::CCustomer()
{
	m_pWaiter = NULL;
}

CCustomer::~CCustomer()
{

}

void CCustomer::do_take_order()
{
	int randnum = rand();
	printf("%d %d %d \n", m_id, 0, randnum);
	CCommand* pCommand = new CCommand(m_id, 0, randnum);
	m_pWaiter->push(pCommand);
}

void CCustomer::set_waiter(CWaiter* pWaiter)
{
	m_pWaiter = pWaiter;
}

bool CCustomer::notify(void* pvoid)
{
	//execute(pvoid);
	CCommand* pCommand = (CCommand*)pvoid;
	printf("%d %d %d \n", pCommand->From(),pCommand->To(),pCommand->Cmd());
	return true;
}
//////////////////////////////////////////////////////////////////////////

CWaiter::CWaiter()
{

}

CWaiter::~CWaiter()
{

}

bool CWaiter::notify(void* pvoid)
{
	execute(pvoid);
	return true;
}

void CWaiter::execute(void* pvoid)
{
	CCommand* pCommand = (CCommand*)pvoid;
	CPerson* pPerson = NULL;
	for (std::list<CObserverMgr*>::iterator iter = m_list_observer.begin();
		iter != m_list_observer.end();
		++ iter)
	{
		pPerson = dynamic_cast<CPerson*>(*iter);
		if (pPerson->get_id() == pCommand->From())
		{
			(*iter)->notify(pvoid);
			break;
		}
	}
}
