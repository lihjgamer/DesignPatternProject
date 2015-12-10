#include "ClassSingleton.h"

CClassSingleton::CClassSingleton(void)
{
	x = 10;
}

CClassSingleton::~CClassSingleton(void)
{
}

CClassSingleton& CClassSingleton::Singleton()
{
	static CClassSingleton instance;
	return instance;
}
