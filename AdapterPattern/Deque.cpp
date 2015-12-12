#include "Deque.h"
#include <stdio.h>

#pragma warning(disable:4996)

#ifdef TEST_DEQUE
#define DEQUE_HELP_COMMAND \
	printf("please input command : \n"); \
	printf("command 1 : push front \n"); \
	printf("command 2 : push back  \n"); \
	printf("command 3 : pop  front \n"); \
	printf("command 4 : pop  back  \n"); \
	printf("command 5 : print deque\n");
#endif // TEST_API


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

int CDeque::pop_back()
{
	int nret = -1;

	if (empty())
	{
		return nret;
	}

	deque_node* pnode = tail;
	tail = pnode->pre;
	tail == nullptr ? head = tail : tail->next = nullptr;

	nret = pnode->data;
	delete pnode;
	pnode = nullptr;

	return nret;
}

int CDeque::pop_front()
{
	int nret = -1;

	if (empty())
	{
		return nret;
	}

	deque_node* pnode = head;
	head = pnode->next;
	head == nullptr ? tail = head : head->pre = nullptr;

	nret = pnode->data;
	delete pnode;
	pnode = nullptr;
	return nret;
}

#ifdef TEST_DEQUE
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

void CDeque::test()
{
	CDeque queuetest;
	for (int i = 0; i < 10; i++)
	{
		queuetest.push_back(i);
	}

	DEQUE_HELP_COMMAND;

	int command = 0;
	int val = 0;
	scanf("%d %d", &command, &val);
	while (command != 0)
	{
		switch (command)
		{
		case 1:
			queuetest.push_front(val);
			break;
		case 2:
			queuetest.push_back(val);
			break;
		case 3:
			queuetest.pop_front();
			break;
		case 4:
			queuetest.pop_back();
			break;
		case 5:
			queuetest.printdeque();
			break;
		default:
			break;
		}
		DEQUE_HELP_COMMAND;
		scanf("%d %d", &command, &val);
	}
}

#endif