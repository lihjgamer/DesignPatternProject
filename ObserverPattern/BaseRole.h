#pragma once
#include <string>
#include <list>

#include "Observer.h"
class CBaseRole
{
public:
	CBaseRole(std::string name, int role, int age);
	virtual ~CBaseRole();

	inline std::string getname()
	{
		return m_name;
	}

	inline int getrole()
	{
		return m_role;
	}

	inline int getage()
	{
		return m_age;
	}




	virtual void update(unsigned long timestamp) = 0;

private:
	std::string m_name;
	int         m_role;
	int         m_age;
};

