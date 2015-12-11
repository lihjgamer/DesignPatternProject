#include "Tomatoes.h"
#include <stdio.h>

CTomatoes::CTomatoes(std::string name)
:CGoods(name)
{

}

CTomatoes::~CTomatoes()
{

}

void CTomatoes::PrintMsg()
{
	printf("name : %s\n", m_goods_name.c_str());
}

CTomatoesA::CTomatoesA(int color, std::string name)
:CTomatoes(name)
{
	m_tomatoes_color = color;
}

CTomatoesA::~CTomatoesA()
{

}

void CTomatoesA::PrintMsg()
{
	printf("color : %d\n", m_tomatoes_color);

	CTomatoes::PrintMsg();
}
