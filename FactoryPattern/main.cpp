#include <stdio.h>
#include <stdlib.h>

#include "Goods.h"
#include "Potato.h"
#include "Tomatoes.h"

#include "SimpleFactory.h"

#include "FactoryFucntion.h"

#define SimpleFactotyTest(ClassName,type)\
	{\
	printf("SimpleFactoryTest Begin\n");\
		ClassName val; \
		pgoods = val.create(type); \
		if (pgoods != nullptr)\
		{\
		pgoods->PrintMsg(); \
		val.destroy(pgoods); \
		}\
	printf("SimpleFactoryTest End\n"); \
	}\
	


#define FactotyFunctionTest(ClassName) \
	{\
		ClassName val; \
		pgoods = val.create(); \
		if (pgoods != nullptr)\
		{\
			pgoods->PrintMsg(); \
			val.destroy(pgoods); \
		}\
	}\

int main(int argc, char** argv)
{

	CGoods* pgoods = nullptr;
	// 简单工程模式测试
	
	/*
		goods_type_potato
		goods_type_potato_a
		goods_type_tomatoes
		goods_type_tomatoes_a
	*/
	/*
	CSimpleFactory simplefactory;
	pgoods = simplefactory.create(goods_type_potato_a);
	if (pgoods != nullptr)
	{
		pgoods->PrintMsg();
		simplefactory.destroy(pgoods);
	}
	*/

	SimpleFactotyTest(CSimpleFactory, goods_type_potato);
	SimpleFactotyTest(CSimpleFactory, goods_type_potato_a);
	SimpleFactotyTest(CSimpleFactory, goods_type_tomatoes);
	SimpleFactotyTest(CSimpleFactory, goods_type_tomatoes_a);


	// 工厂方法测试
	/*
	CFactoryPotato factorypotato;
	pgoods = factorypotato.create();
	if (pgoods != nullptr)
	{
	pgoods->PrintMsg();
	factorypotato.destroy(pgoods);
	}
	*/
	

	FactotyFunctionTest(CFactoryPotato);
	FactotyFunctionTest(CFactoryPotatoA);
	FactotyFunctionTest(CFactoryTomatoes);
	FactotyFunctionTest(CFactoryTomatoesA);




	system("pause");
	return 0;
}