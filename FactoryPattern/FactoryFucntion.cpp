#include "FactoryFucntion.h"

#include "Tomatoes.h"
#include "Potato.h"

#include <assert.h>

CFactoryFucntion::CFactoryFucntion()
{
}


CFactoryFucntion::~CFactoryFucntion()
{
}

void CFactoryFucntion::destroy(CGoods* pgoods)
{
	// assert 断言错误在控制台 空指针 二次销毁 不会导致程序崩溃 
	// 特殊情况下回奔溃 如 ： MFC
	assert(pgoods != nullptr);
	delete pgoods;
}

CGoods* CFactoryPotato::create()
{
	CPotato* pgoods = new CPotato("factoryfunction potato");
	return pgoods;
}

CGoods* CFactoryPotatoA::create()
{
	CPotatoA* pgoods = new CPotatoA(12,"factoryfunction potatoa");
	return pgoods;
}

CGoods* CFactoryTomatoes::create()
{
	CTomatoes* pgoods = new CTomatoes("factoryfunction tomatoes");
	return pgoods;
}

CGoods* CFactoryTomatoesA::create()
{
	CTomatoesA* pgoods = new CTomatoesA(11, "factoryfunction tomatoesa");
	return pgoods;
}
