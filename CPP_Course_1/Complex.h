#pragma once

namespace complexNumbers {
	class Complex
	{
	private:
		double real;
		double imaginary;
	public:
		Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

		~Complex() {}

		Complex(const Complex& other) {
			real = other.real;
			imaginary = other.imaginary;
		}
		double getReal() const { return real; }
		double getImaginary() const { return imaginary; }

		Complex& operator=(const Complex& other);
	};


	//werkt niet?
	//ostream &operator<<(ostream &out, const Complex &c);
	inline Complex operator+(const Complex& c1, const Complex& c2)
	{
		Complex complex(c1.getReal() + c2.getReal(), c1.getImaginary() + c2.getImaginary());
		return complex;
	}
}
