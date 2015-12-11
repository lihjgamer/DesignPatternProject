#include "SimpleFactory.h"

#include "Goods.h"
#include "Potato.h"
#include "Tomatoes.h"


int CSimpleFactory::m_ref = 0;
CSimpleFactory::CSimpleFactory()
{
	m_ref++;
	printf("simple constructor : %d\n", m_ref);
}


CSimpleFactory::~CSimpleFactory()
{
}

CGoods* CSimpleFactory::create(e_goods_type type)
{
	CGoods* pgoods = nullptr;
	switch (type)
	{
	case goods_type_potato:
		pgoods = new CPotato("potato");
		break;
	case goods_type_potato_a:
		pgoods = new CPotatoA(1,"potatoa");
		break;
	case goods_type_tomatoes:
		pgoods = new CTomatoes("tomatoes");
		break;
	case goods_type_tomatoes_a:
		pgoods = new CTomatoesA(3,"tomatoesa");
		break;
	default:
		break;
	}

	return pgoods;
}

void CSimpleFactory::destroy(CGoods* pgoods)
{
	delete pgoods;
}
