#pragma once
/*
	����ģʽ
	�ص㣺
	1��˽�еĹ��캯������������
	2������ֻ��һ������ʵ��
*/
class CClassSingleton
{
	// ��̬��Ա���� �����ṩ�Ľӿ�
public:
	static CClassSingleton& Singleton();

	inline int get_x()
	{
		return x;
	}
	inline void set_x(int x)
	{
		this->x = x;
	}

private:
	int x;
	//int y;
private:
	CClassSingleton(void);
	~CClassSingleton(void);

	// ������ �����͸�ֵ
	CClassSingleton(const CClassSingleton&);
	CClassSingleton& operator = (const CClassSingleton& );
};
