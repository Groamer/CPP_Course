#pragma once
#include "stdafx.h"

template<typename  T> class TestTemplate
{
private:
	T obj;
public:
	TestTemplate(T obj);
	void print();
};