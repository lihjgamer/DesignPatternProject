#include "Stack.h"
#include <stdio.h>

#pragma warning(disable:4996)

#ifdef TEST_STACK
#define STACK_HELP_COMMAND \
	printf("please input command : \n"); \
	printf("command 1 : push  \n"); \
	printf("command 2 : pop   \n"); \
	printf("command 3 : print \n");
#endif // TEST_API

CStack::CStack()
{
}


CStack::~CStack()
{
}

void CStack::push(int val)
{
	m_deque.push_back(val);
}

int CStack::pop()
{
	return m_deque.pop_back();
}

#ifdef TEST_STACK
void CStack::test()
{
	CStack stacktest;

	for (int i = 0; i < 10; i++)
	{
		stacktest.push(i);
	}

	STACK_HELP_COMMAND;
	int command = 0;
	int val = 0;
	scanf("%d %d", &command, &val);
	while (command != 0)
	{
		switch (command)
		{
		case 1:
			stacktest.push(val);
			break;
		case 2:
			stacktest.pop();
			break;
		case 3:
			stacktest.printstack();
			break;
		default:
			break;
		}
		STACK_HELP_COMMAND;
		scanf("%d %d", &command, &val);
	}



}

void CStack::printstack()
{
	m_deque.printdeque();
}
#endif