#include "Deque.h"
#include <stdio.h>

CDeque::CDeque()
{
	head = nullptr;
	tail = nullptr;
}


CDeque::~CDeque()
{
	while (head != tail)
	{
		pop_front();
	}
	pop_front();
}

bool CDeque::empty()
{
	bool bempty = false;
	if ( head == tail 
		&& head == nullptr)
	{
		bempty = true;
	}
	return bempty;
}

void CDeque::push_back(int val)
{
	if (empty())
	{
		deque_node* pnode = new deque_node(val);
		if (pnode == nullptr)
		{
			fprintf(stdout, "malloc failed\n");
			return;
		}
		head = tail = pnode;
		return;
	}

	if (tail == nullptr)
	{
		return;
	}

	deque_node* pnode = tail;

	pnode->next = new deque_node(val);
	pnode->next->pre = pnode;
	tail = pnode->next;
}

void CDeque::push_front(int val)
{
	if (empty())
	{
		deque_node* pnode = new deque_node(val);
		if (pnode == nullptr)
		{
			fprintf(stdout, "malloc failed\n");
			return;
		}
		head = tail = pnode;
		return;
	}

	if (head == nullptr)
	{
		return;
	}

	deque_node* pnode = head;

	head = new deque_node(val);
	head->next = pnode;
	pnode->pre = head;

}

void CDeque::pop_back()
{
	if (empty())
	{
		return;
	}

	deque_node* pnode = tail;
	tail = pnode->pre;
	tail == nullptr ? head = tail : tail->next = nullptr;

	delete pnode;
	pnode = nullptr;


}

void CDeque::pop_front()
{
	if (empty())
	{
		return;
	}

	deque_node* pnode = head;
	head = pnode->next;
	head == nullptr ? tail = head : head->pre = nullptr;

	delete pnode;
	pnode = nullptr;
}

#ifdef TEST_API
void CDeque::printdeque()
{
	printf("next print\n");
	deque_node* pnode = head;
	while (true)
	{
		if (pnode == nullptr)
		{
			break;
		}
		printf("%d ", pnode->data);
		pnode = pnode->next;
	}
	printf("\n");

	
	printf("pre print\n");
	pnode = tail;
	while (true)
	{
		if (pnode == nullptr)
		{
			break;
		}
		printf("%d ", pnode->data);
		pnode = pnode->pre;
	}
	printf("\n");
}
#endif