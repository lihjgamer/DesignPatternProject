#pragma once

#include "Goods.h"

class CTomatoes : public CGoods
{
public:
	CTomatoes(std::string name);
	~CTomatoes();
	
	void PrintMsg();

};

class CTomatoesA : public CTomatoes
{
public:
	CTomatoesA(int color, std::string name);
	~CTomatoesA();

	void PrintMsg();
private:
	int m_tomatoes_color; 
};



