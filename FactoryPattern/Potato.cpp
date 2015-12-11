#include "Potato.h"
#include <stdio.h>

CPotato::CPotato(std::string name)
:CGoods(name)
{

}

CPotato::~CPotato()
{

}

void CPotato::PrintMsg()
{
	printf("name : %s\n", m_goods_name.c_str());
}

CPotatoA::CPotatoA(int sharp, std::string name)
:CPotato(name)
{
	m_potate_sharp = sharp;
}

CPotatoA::~CPotatoA()
{

}

void CPotatoA::PrintMsg()
{
	printf("sharp : %d\n", m_potate_sharp);
	CPotato::PrintMsg();
}
