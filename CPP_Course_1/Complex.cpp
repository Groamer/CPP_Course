#include "stdafx.h"
#include "Complex.h"
#include <fstream>

using namespace complexNumbers;

Complex & Complex::operator=(const Complex & other)
= default;


std::ostream &operator<<(std::ostream &out, const Complex &c) {
	out << c.getReal();
	return out;
}
