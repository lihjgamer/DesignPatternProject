#pragma once

template <class T>
class CIterator
{
public:
	CIterator(){}
	virtual ~CIterator(){}

	virtual T first() = 0;
	virtual T next() = 0;
	virtual bool end() = 0;
};
