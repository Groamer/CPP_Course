#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

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
	void print() {
		cout << "id: " << id << " name: " << name << endl;
	}
	friend ostream& operator<<(ofstream &os, const Test &test) {
		os << test.id;
	}

};


int main() {
	Test test1(10, "Vincent");
	cout << &test1;
}