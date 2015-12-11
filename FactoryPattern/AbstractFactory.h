#pragma once


class CGoods;
class CAbstractFactory
{
public:
	virtual CGoods* create() = 0;
	virtual CGoods* create_a() = 0;

	void            destroy(CGoods* pgoods);
public:
	CAbstractFactory();
	~CAbstractFactory();
};


class CPotatoFactory : public CAbstractFactory
{
public:

	virtual CGoods* create() override;

	virtual CGoods* create_a() override;

};

class CTomatoesFactory : public CAbstractFactory
{
public:

	virtual CGoods* create() override;

	virtual CGoods* create_a() override;

};
