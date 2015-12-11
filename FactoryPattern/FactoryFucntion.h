#pragma once

/*
	����ģʽ ��
	��װ ����ʵ��ϸ��

	��ģʽΪ ����������

	�Ӽ򵥹����б仯���������������󻯣��Ӷ������� N �й���
	ʵ��������� ���� ��� ԭ��
	ֻ�� ÿ����һ����Ʒ ��Ҫ ����һ���µĹ��������³����й���Ĺ�����
	��˿��Խ�һ�� �Թ������г��󣨳��󹤳�ģʽ����ÿһ����������һ�� ��Ʒ
	�Ľ�ǰ �� һ����������һ�ֲ�Ʒ
	�Ľ��� �� һ����������һ���Ʒ
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

