#include "AbstractFactory.h"

#include "Goods.h"
#include "Potato.h"
#include "Tomatoes.h"

CAbstractFactory::CAbstractFactory()
{
}


CAbstractFactory::~CAbstractFactory()
{
}

void CAbstractFactory::destroy(CGoods* pgoods)
{
	delete pgoods;
}

CGoods* CPotatoFactory::create()
{
	CPotato* pgoods = new CPotato("abstract factory potato");
	return pgoods;
}

CGoods* CPotatoFactory::create_a()
{
	CPotatoA* pgoods = new CPotatoA(12,"abstract factory potato");
	return pgoods;
}

CGoods* CTomatoesFactory::create()
{
	CTomatoes* pgoods = new CTomatoes("abstract factory tomatoes");
	return pgoods;
}

CGoods* CTomatoesFactory::create_a()
{
	CTomatoesA* pgoods = new CTomatoesA(13,"abstract factory tomatoes");
	return pgoods;
}
