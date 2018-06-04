#pragma once
#include "stdafx.h"

template<class  T> class Template
{
private:
	T obj;
public:

	explicit Template(T obj)
	{
		this->obj = obj;
	};
	void print()
	{
		std::cout << this->obj;
	}
};