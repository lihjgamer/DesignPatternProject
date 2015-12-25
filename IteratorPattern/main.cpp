#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

int main(int argc, char* argv[])
{

	CDeque<int*> qq;


	int parray[10] = { 0 };
	for (int i = 0; i < 10; i ++)
	{
		parray[i] = i;
	}


	qq.push_front(parray + 3);
	qq.push_front(parray + 4);
	qq.push_front(parray + 5);
	qq.push_front(parray + 6);

	qq.push_back(parray + 7);
	qq.push_back(parray + 1);
	qq.push_back(parray + 2);


	for (int* v = qq.first(); !qq.end(); v = qq.next())
	{
		printf("%d\n", *v);
	}

	system("pause");
	return 0;
}