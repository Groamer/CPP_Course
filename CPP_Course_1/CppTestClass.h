#pragma once
#include <ostream>
#include <iostream>

using namespace std;

class CppTestClass {

public:
	CppTestClass() :
		id(12), name("defaultName") {
		cout << "Hallo" << endl;
	}

	~CppTestClass() = default;

	CppTestClass(int id, std::string name) : id(id), name(name) {}

	/*CppTestClass(const CppTestClass& other) {
	*this = other;
	}*/
	const CppTestClass &operator= (const CppTestClass &other) {
		id = other.id;
		name = other.name;

		return *this;
	}
	void setName(std::string name) { this->name = name; }
	void  print() const {
		std::cout << "id: " << id << " name: " << name << std::endl;
	}
	friend ostream& operator<<(ostream &os, const CppTestClass &test);

private:
	int id;
	std::string name;
};

ostream& operator<<(ostream &os, const CppTestClass &test) {
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