#include "stdafx.h"
#include "Complex.h"
#include <fstream>

using namespace complexNumbers;

Complex::Complex(const Complex & other) = default;

Complex & Complex::operator=(const Complex & other) = default;

std::ostream & complexNumbers::operator<<(std::ostream & out, const Complex & other)
{
	return out << "real: " << other.real << "| Imaginary: " << other.imaginary;
}
