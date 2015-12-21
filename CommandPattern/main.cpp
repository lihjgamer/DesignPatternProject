#include <stdio.h>
#include <stdlib.h>

#include "Person.h"
#include "Command.h"

int main(int argc, char* argv[])
{

	CBaker g_baker[10];
	CCustomer g_customer[10];
	CWaiter   g_waiter;

	// 将服务员
	for (int i = 0; i < 10; i ++)
	{
		g_baker[i].register_observer(&g_waiter);
		g_baker[i].set_waiter(&g_waiter);
	}

	for (int i = 0; i < 10; i ++)
	{
		g_waiter.register_observer(g_customer + i);
		g_customer[i].set_waiter(&g_waiter);
	}


	for (int i = 0; i < 10; i++)
	{
		g_customer[i].do_take_order();
	}

	while (true)
	{
		for (int i = 0; i < 10; i ++)
		{
			g_baker[i].active();
		}
	}

}