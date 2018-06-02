#include "stdafx.h"
#include <iostream>
#include <string>
#include "Complex.h"

using namespace std;
using namespace complexNumbers;

class Test{
private:
	int id;
	string name;
public:
	Test() :id(0), name("") {}

	Test(int id, string name) : id(id), name(name) {}

	Test(const Test& other) {
		*this = other;
	}
	const Test &operator= (const Test &other) {
		id = other.id;
		name = other.name;
		
		return *this;
	}
	void  print() const {
		cout << "id: " << id << " name: " << name << endl;
	}
	friend ostream& operator<<(ostream &os, const Test &test);
	
};

ostream& operator<<(ostream &os, const Test &test) {
	return os << test.id << " : " << test.name;
}

int main() {
	Test test1(10, "Vincent");
	cout << test1 << endl;

	Complex c1(10, 12);
	Complex c2(2, 3);
	Complex c3 = c1 + c2;
	//cout << c1 << endl;
}
