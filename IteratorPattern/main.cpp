#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

int main(int argc, char* argv[])
{

	CDeque<int> qq;

	qq.push_back(1);
	qq.push_back(2);
	qq.push_front(3);
	qq.push_front(4);
	qq.push_front(5);
	qq.push_front(6);
	qq.push_back(7);


	for (int v = qq.first(); !qq.end(); v = qq.next())
	{
		printf("%d\n", v);
	}

	system("pause");
	return 0;
}