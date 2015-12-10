#pragma once
/*
	单例模式
	特点：
	1、私有的构造函数和析构函数
	2、有且只有一个对象实例
*/
class CClassSingleton
{
	// 静态成员函数 对外提供的接口
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

	// 不允许 拷贝和赋值
	CClassSingleton(const CClassSingleton&);
	CClassSingleton& operator = (const CClassSingleton& );
};
