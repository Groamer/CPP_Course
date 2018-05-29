#include "stdafx.h"
#include "MyException.h"

char const* MyException::what() const
{
	return "something bad happened";
}
