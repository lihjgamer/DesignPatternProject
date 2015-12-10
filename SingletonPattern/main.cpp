#include <stdio.h>
#include <stdlib.h>

#include "ClassSingleton.h"

int main(int argc,char** argv)
{
	printf("%d\n",CClassSingleton::Singleton().get_x());
	system("pause");
	return 0;
}