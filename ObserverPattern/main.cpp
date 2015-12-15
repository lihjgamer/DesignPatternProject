#include <stdio.h>
#include <stdlib.h>

#include <time.h>

#include "BaseRole.h"
#include "Observer.h"
#include "Son.h"
#include "Daddy.h"


int main(int argc, char* argv[])
{
	CSon son("son",1,1);
	CDaddy daddy("father", 2, 30);

	son.register_observer(&daddy);

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