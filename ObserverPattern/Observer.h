#pragma once

/*
	观察者 基类
*/
class CObserver
{
public:
	CObserver();
	virtual ~CObserver();

	virtual void notify() = 0;
};

