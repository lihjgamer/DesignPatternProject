#pragma once

#include <string>

class CGoods
{
public:
	CGoods(std::string goods_name);
	virtual ~CGoods();

	std::string Goods_name() const { return m_goods_name; }
	void Goods_name(std::string val) { m_goods_name = val; }
	// don't need this function ,because they will convert to string automaticly;
	// void Goods_name(const char* pval) { m_goods_name = pval; } 

	virtual void PrintMsg() = 0;

protected:
	std::string m_goods_name;


};

