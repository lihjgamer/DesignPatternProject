#include "Queue.h"
#include <stdio.h>

#pragma warning(disable:4996)

#ifdef TEST_QUEUE
#define QUEUE_HELP_COMMAND \
	printf("please input command : \n"); \
	printf("command 1 : push  \n"); \
	printf("command 2 : pop   \n"); \
	printf("command 3 : print \n");
#endif // TEST_API
CQueue::CQueue()
{
}


CQueue::~CQueue()
{
}

void CQueue::push(int val)
{
	m_deque.push_front(val);
}

int CQueue::pop()
{
	return m_deque.pop_back();
}

#ifdef TEST_QUEUE
void CQueue::printqueue()
{
	m_deque.printdeque();
}

void CQueue::test()
{
	CQueue queuetest;

	for (int i = 0; i < 10; i++)
	{
		queuetest.push(i);
	}

	QUEUE_HELP_COMMAND;
	int command = 0;
	int val = 0;
	scanf("%d %d", &command, &val);
	while (command != 0)
	{
		switch (command)
		{
		case 1:
			queuetest.push(val);
			break;
		case 2:
			queuetest.pop();
			break;
		case 3:
			queuetest.printqueue();
			break;
		default:
			break;
		}
		QUEUE_HELP_COMMAND;
		scanf("%d %d", &command, &val);
	}
}
#endif
