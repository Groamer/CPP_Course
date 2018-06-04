#pragma once
#include "stdafx.h"

template<class  T> class TestTemplate
{
public:
	T obj;

	explicit TestTemplate(T obj)
	{
		this->obj = obj;
	};
	void print()
	{
		
	}
};