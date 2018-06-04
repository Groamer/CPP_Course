#include "stdafx.h"
#include <iostream>
#include "TestTemplate.h"

template <class  T>
void TestTemplate<T>::print()
{
	std::cout << this->obj;
}
