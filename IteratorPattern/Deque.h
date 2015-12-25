#pragma once
#include <stdio.h>
//#define TEST_DEQUE
#include "Iterator.h"
#pragma warning(disable:4996)

#ifdef TEST_DEQUE
#define DEQUE_HELP_COMMAND \
	printf("please input command : \n"); \
	printf("command 1 : push front \n"); \
	printf("command 2 : push back  \n"); \
	printf("command 3 : pop  front \n"); \
	printf("command 4 : pop  back  \n"); \
	printf("command 5 : print deque\n");
#endif // TEST_DEQUE

template <class T>
class CDeque : public CIterator<T>
{
public:
	CDeque()
	{
		head = tail = nullptr;
		cur = nullptr;
	}
	~CDeque()
	{
		while (head != tail)
		{
			pop_front();
		}
		pop_front();
	}

	bool empty()
	{
		bool bempty = false;
		if (head == tail
			&& head == nullptr)
		{
			bempty = true;
		}
		return bempty;
	}

	void push_back(T val)
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
	void push_front(T val)
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

	T	 pop_back()
	{
		T nret(0);

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
	T	 pop_front()
	{
		// 这里初始化 是否会有问题？？？
		T nret(0);

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

	T first()
	{
		T nret(0);

		if (empty())
		{
			cur = nullptr;
			return nret;
		}

		nret = head->data;
		cur = head;
		return nret;
	}

	T next()
	{
		T nret(0);

		if (cur->next == nullptr)
		{
			cur = nullptr;
			return nret;
		}

		nret = cur->next->data;
		cur = cur->next;
		return nret;
	}

	bool end()
	{
		return cur == nullptr;
	}
#ifdef TEST_DEQUE
	void printdeque()
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
	static void test()
	{
		CDeque<T> queuetest;
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


private:
	typedef struct deque_node 
	{
		T			data;
		deque_node* pre;
		deque_node* next;

		deque_node(T  val)
		{
			data = val;
			pre  = nullptr;
			next = nullptr;
		}
	}deque_node;
	
	deque_node* head;
	deque_node* tail;

	deque_node* cur;
};

