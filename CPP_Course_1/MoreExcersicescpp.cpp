#include "stdafx.h"
#include <iostream>
#include <string>
#include "Complex.h"
#include "Template.h"
#include "CppTestClass.h"

using namespace std;
using namespace complexNumbers;


int main4() {
	//CppTestClass *test1 = new CppTestClass(13, "test1");
	//cout << *test1 << endl; 

	std::cout << "Hello";
	CppTestClass test2;
	std::cout << " World";
	//test2.print();


	CppTestClass* test3 = new CppTestClass();
	std::cout << " World";
	test3->print();

	Complex ctest;
	//Complex c1(10, 12);
	//Complex c2(2, 3);
	//Complex c3 = c1 + c2;

	//cout << c3 << endl;

	//int a = 5;
	//int b = 10;
	//
	////calls swap with & 
	//swap(a, b);

	////calls swap with *
	//swap(&a, &b);

	//Template<int> t(5);
	//t.print();
	return 0;
}
