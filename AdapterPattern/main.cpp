#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

#pragma warning(disable:4996)
#define HELP_COMMAND \
printf("please input command : \n");\
printf("command 1 : push front \n");\
printf("command 2 : push back  \n");\
printf("command 3 : pop  front \n");\
printf("command 4 : pop  back  \n");\
printf("command 5 : print deque\n");


int main(int argc, char** argv)
{
	CDeque queuetest;
	for (int i = 0; i < 10; i ++)
	{
		queuetest.push_back(i);
	}

	HELP_COMMAND;

	int command = 0;
	int val = 0;
	scanf("%d %d", &command,&val);
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
		HELP_COMMAND;
		scanf("%d %d", &command, &val);
	}
	system("pause");
	return 0;
}
