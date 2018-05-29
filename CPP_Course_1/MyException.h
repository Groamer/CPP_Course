#pragma once
#include <exception>

class MyException: public std::exception
{
	public:
		char const* what() const override;
};

