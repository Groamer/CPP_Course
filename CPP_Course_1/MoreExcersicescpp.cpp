#include "stdafx.h"
#include <iostream>
#include <string>
#include "Complex.h"
#include "Template.h"
#pragma once

using namespace std;
using namespace complexNumbers;

class Test{
private:
	int id;
	string name;
public:
	Test() {
		id = 12;
		name = "defaultName";
	}

	Test(int id, string name) : id(id), name(name) {}

	/*Test(const Test& other) {
		*this = other;
	}*/
	const Test &operator= (const Test &other) {
		id = other.id;
		name = other.name;
		
		return *this;
	}
	void setName(string name) { this->name = name; }
	void  print() const {
		cout << "id: " << id << " name: " << name << endl;
	}
	friend ostream& operator<<(ostream &os, const Test &test);
	
};

ostream& operator<<(ostream &os, const Test &test) {
	return os << test.id << " : " << test.name;
}

void swap(int *a, int *b) {
	cout << *a << " + " << *b << endl;

	int oldA = *a;
	*a = *b;
	*b = oldA;

	cout << *a << " + " << *b << endl;
}

void swap(int &a, int &b) {
	cout << a << " + " << b << endl;

	int oldA = a;
	a = b;
	b = oldA;

	cout << a << " + " << b << endl;
}


int main() {
	Test *test1 = new Test(13, "test1");
	cout << *test1 << endl; 

	Test test2(12, "test2");
	test2.print();

	//Complex ctest;
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
