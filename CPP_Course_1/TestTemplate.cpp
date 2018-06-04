#include "stdafx.h"
#include <iostream>
#include "TestTemplate.h"

template <typename T>
TestTemplate<T>::TestTemplate(T obj)
{
	this->obj = obj;
}

template <typename  T>
void TestTemplate<T>::print()
{
	std::cout << this->obj;
}
