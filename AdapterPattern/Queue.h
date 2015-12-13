#pragma once
#include "Deque.h"

#define TEST_QUEUE
class CQueue
{
public:
	void push(int val);
	int  pop();

#ifdef TEST_QUEUE
	void printqueue();
	static void test();
#endif
public:
	CQueue();
	~CQueue();
private:
	CDeque<int> m_deque;
};

