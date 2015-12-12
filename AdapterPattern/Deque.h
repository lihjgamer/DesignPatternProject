#pragma once

#define TEST_DEQUE

class CDeque
{
public:
	CDeque();
	~CDeque();

	bool empty();

	void push_back(int val);
	void push_front(int val);

	int  pop_back();
	int  pop_front();

#ifdef TEST_DEQUE
	void printdeque();
	static void test();
#endif


private:
	typedef struct deque_node 
	{
		int		    data;
		deque_node* pre;
		deque_node* next;

		deque_node(int val)
		{
			data = val;
			pre  = nullptr;
			next = nullptr;
		}
	}deque_node;
	
	deque_node* head;
	deque_node* tail;
};

