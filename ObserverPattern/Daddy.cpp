#include "Daddy.h"


CDaddy::CDaddy(std::string name, int role, int age)
:CBaseRole(name,role,age)
{
}


CDaddy::~CDaddy()
{
}

void CDaddy::update(unsigned long timestamp)
{
}

void CDaddy::notify()
{
	printf("my son has grown up\n");
}
