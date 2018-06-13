#pragma once
#include <fstream>
namespace complexNumbers {
	class Complex
	{
	private:
		double real;
		double imaginary;
	public:
		Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

		~Complex() {}

		Complex(const Complex& other);

		double getReal() const { return real; }
		double getImaginary() const { return imaginary; }

		Complex& operator=(const Complex& other);

		//ostream needs to be a friend to work OR outside of class, but then you cant acces private variable --> getters
		friend std::ostream& operator<< (std::ostream &out, const Complex &other);
	};
		

	inline Complex operator+(const Complex& c1, const Complex& c2)
	{
		Complex complex(c1.getReal() + c2.getReal(), c1.getImaginary() + c2.getImaginary());
		return complex;
	}
}
