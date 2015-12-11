#pragma once

#include "Goods.h"

class CPotato : public CGoods
{
public:
	CPotato(std::string name);
	~CPotato();

	void PrintMsg();

};



class CPotatoA : public CPotato
{
public:
	CPotatoA(int sharp, std::string name);
	~CPotatoA();
	void PrintMsg();

private:
	int m_potate_sharp;
};


class CPotatoB : public CPotato
{

};
