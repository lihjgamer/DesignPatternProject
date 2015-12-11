#pragma once

/*
	工厂模式 ：
	封装 隐藏实现细节

	该模式为 工厂方法：

	从简单工厂中变化而来，将工厂抽象化，从而衍生出 N 中工厂
	实现了软件的 开放 封闭 原则
	只是 每增加一个产品 就要 创建一个新的工厂，导致程序中过多的工厂类
	因此可以进一步 对工厂进行抽象（抽象工厂模式），每一个工厂生产一类 产品
	改进前 ： 一个工厂生产一种产品
	改进后 ： 一个工厂生产一类产品
*/

class CGoods;
class CFactoryFucntion
{
public :
	virtual CGoods* create() = 0;
	void    destroy(CGoods* pgoods);
public:
	CFactoryFucntion();
	~CFactoryFucntion();
};

class CFactoryPotato : public CFactoryFucntion
{
public:
	CGoods* create();
};

class CFactoryPotatoA : public CFactoryFucntion
{
public:
	CGoods* create();

};

class CFactoryTomatoes : public CFactoryFucntion
{
public:
	CGoods* create();

};
class CFactoryTomatoesA : public CFactoryFucntion
{
public:
	CGoods* create();
};

