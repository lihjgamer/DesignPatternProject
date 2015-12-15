#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	简单介绍：
	本文列举了 父亲和儿子
	父亲比较关心儿子的成长

	因此父亲作为观察者，当儿子长大后，回通知父亲

*/

//#include "BaseRole.h"
//#include "Observer.h"
#include "Son.h"
#include "Daddy.h"


int main(int argc, char* argv[])
{
	CSon son("son",1,1);
	CDaddy daddy("father", 2, 30);

	son.register_observer(&daddy);
	// son.unregister_observer(&daddy);
	// son.unregister_observer(0);
	// son.unregister_all_observer();

	long long ulcurrtime = time(NULL);
	long long ulpretime = ulcurrtime;
	while (1)
	{
		ulcurrtime = time(NULL);
		if (ulcurrtime - ulpretime < 2)
		{
			continue;
		}

		ulpretime = ulcurrtime;
		son.update(0);
		daddy.update(0);

	}

	system("pause");
	return 0;
}