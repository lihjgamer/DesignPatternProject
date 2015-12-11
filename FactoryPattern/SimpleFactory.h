#pragma once

/*
	工厂模式
	封装 实现细节

	该模式为简单工厂模式

	缺点 ： 违背了软件的 开放封闭 原则
	每当有新的产品需要加入时，就需要修改代码实现

	因此有了 工厂方法 模式 
*/
enum e_goods_type
{
	goods_type_potato,
	goods_type_potato_a,
	goods_type_tomatoes,
	goods_type_tomatoes_a,
};

class CGoods;
/*
class CPotato;
class CPotatoA;
class CTomatoes;
class CTomatoesA;
*/
class CSimpleFactory
{
public:
	CGoods* create(e_goods_type type);
	void    destroy(CGoods* goods);
public:

	static int m_ref;

	CSimpleFactory();
	~CSimpleFactory();
};

