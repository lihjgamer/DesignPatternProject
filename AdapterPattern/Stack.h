#pragma once
#include "Deque.h"

#define TEST_STACK
class CStack
{
public:
	void push(int val);
	int  pop();
#ifdef TEST_STACK
	static void test();
	void printstack();
#endif
public:
	CStack();
	~CStack();

private:
	CDeque<int> m_deque;
};

