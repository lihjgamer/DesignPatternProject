#include <stdio.h>
#include <stdlib.h>

// �ڴ�й¶���

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <DbgHelp.h>
#include <crtdbg.h>
#pragma comment(lib,"dbghelp.lib")


#include "Deque.h"
#include "Stack.h"
#include "Queue.h"

int main(int argc, char** argv)
{
	_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(217594);

	printf("deque test\n");
	CDeque<int>::test();

	printf("stack test\n");
	CStack::test();

	printf("queue test\n");
	CQueue::test();

	system("pause");
	return 0;
}
