#pragma once

/*
	����ģʽ
	��װ ʵ��ϸ��

	��ģʽΪ�򵥹���ģʽ

	ȱ�� �� Υ��������� ���ŷ�� ԭ��
	ÿ�����µĲ�Ʒ��Ҫ����ʱ������Ҫ�޸Ĵ���ʵ��

	������� �������� ģʽ 
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

