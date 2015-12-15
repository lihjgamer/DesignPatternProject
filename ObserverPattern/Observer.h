#pragma once
class CObserver
{
public:
	CObserver();
	virtual ~CObserver();

	virtual void notify() = 0;
};

