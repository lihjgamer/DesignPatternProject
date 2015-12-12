#include <stdio.h>
#include <stdlib.h>

#include "Goods.h"
#include "Potato.h"
#include "Tomatoes.h"

#include "SimpleFactory.h"

#include "FactoryFucntion.h"

#include "AbstractFactory.h"


#define SimpleFactotyTest(ClassName,type)\
	{\
		ClassName val; \
		pgoods = val.create(type); \
		if (pgoods != nullptr)\
		{\
		pgoods->PrintMsg(); \
		val.destroy(pgoods); \
		}\
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

#define AbstractFactoryTest(ClassName)\
	{\
		ClassName val; \
		pgoods = val.create();\
		if (pgoods != nullptr)\
		{\
		pgoods->PrintMsg();\
		val.destroy(pgoods);\
		}\
		pgoods = val.create_a(); \
		if (pgoods != nullptr)\
		{\
		pgoods->PrintMsg(); \
		val.destroy(pgoods); \
		}\
	}\

int main(int argc, char** argv)
{

	CGoods* pgoods = nullptr;
	// �򵥹���ģʽ����
	
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


	// ������������
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

	// ���󹤳����� ����

	AbstractFactoryTest(CTomatoesFactory);
	AbstractFactoryTest(CPotatoFactory);

	system("pause");
	return 0;
}