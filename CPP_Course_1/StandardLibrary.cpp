#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <list>
#include <map>
#include <algorithm>
#include <set>
//vector is resizable
using namespace std;

class Person
{
private:
	string name;
	int age;
public:
	vector<int>* marks;

	Person() { 
		name = "", 
		age = 0; 
	}

	//copy constructor
	Person(const Person& other)
	{
		name = other.name;
		age = other.age;
		marks =  new vector<int>(*other.marks);
	}
	~Person() = default;

	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}

	void print()
	{
		cout << name << " : " << age << endl;
	}

	void lowerVector() {
		marks->pop_back();
	}

	Person& operator=(const Person& other) {
		name = other.name;
		age = other.age;
		marks = new vector<int>(*other.marks);
		return *this;
	}

	bool operator< (const Person& other) const {
		if (name == other.name)
			return age < other.age;
		return name < other.name;
	}

	// mag private members gebruiken
	friend bool comp(const Person& a, const Person& b);
};

bool comp(const Person& a, const Person& b) {
	if (a.name == b.name)
		return a.age < b.age;
	return a.name < b.name;
}

void TryConstructors() {
	// copy constructor is called when the object does not "exist" yet. like Test t2 = t1;
	// assignment operator is called when the object is already there but is copied. like Test t2; t2 = t1

	Person p1 = Person("Vincent", 22);
	Person p2;

	vector<int> allmarks = vector<int>(4, 4);
	p1.marks = &allmarks;
	//copy constructor is called
	//Person p2 = p1;
	p2 = p1;
	

	// if copy constructor is implemented, the p2 value will not have changed.
	// However, if it is not implemented, the pointer of p2 will also point to the p1's pointer
	// and change both p1 and p2 if you change either's pointer variable
	p1.lowerVector();
	
}


void tryVector()
// een vector als argument van een functie kopiert de gehele vector eerst,
// als de lijst niet gemodified hoeft te worden kan er beter pass by reference gebruikt worden
// print(const vector<int>& v);
{
	//presize vector door (x) (kan, hoeft niet)
	vector<string> strings;

	strings.push_back("hello");
	strings.push_back("asdf");
	strings.push_back("sdfg");

	for (int i = 0; i < strings.size(); i++)
	{
		cout << strings[i] << endl;
	}

	/*for (vector<string> ::iterator it = strings.begin(); it != strings.end(); it++)
	{
		cout << *it << endl;
	}*/
}

void MultidimentionalVector()
{
	vector<vector<int>> grid(3, vector<int>(4, 0));

	grid[1].push_back(8);

	for (int row = 0; row < grid.size(); row++)
	{
		string a = "";

		for (auto col = 0; col < grid[row].size(); col++)
		{
			grid[row][col] = col * 12;
			a += std::to_string(grid[row][col]);
		}
		cout << a << endl;
	}
}

void tryList()
{
	list<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_front(0);

	for (list<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
	{
		// dit insert de waarde VOOR het 3e element [0,1,2], dus nummer 2
		if (*it == 2)
		{
			numbers.insert(it, 1234);
		}

		//erasen met een extra ++ omdat de iterator 1 teruggezet wordt
		if (*it == 1)
			it = numbers.erase(it);
		else
			++it;
	}
	for (list<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
	{
		cout << *it << endl;
	}
}

void tryMap()
{
	// een key in een map is uniek
	map<string, int> ages;

	ages["Mike"] = 40;
	ages["Jan"] = 100;
	ages["Bart"] = 22;
	pair<string, int> vincentAge = {"Vincent", 23};

	ages.insert(vincentAge);

	// de iterator point naar een pair van hetzelfde type als de map (map = een list van pairs)
	for (map<string, int>::iterator it = ages.begin(); it != ages.end(); ++it)
	{
		pair<string, int> age = *it;
	}


	for (map<string, int>::iterator it = ages.begin(); it != ages.end(); ++it)
	{
		cout << it->first << " is" << it->second << endl;
	}

	if (ages.find("Vicky") != ages.end())
	{
		//checken of er een item in de map aanwezig is
	}
}

void CustomMap()
{
	map<int, Person> people;

	people[0] = Person("Vincent", 22);
	people[1] = Person("Bart", 40);
	people[2] = Person("Paul", 100);

	for (map<int, Person>::iterator it = people.begin(); it != people.end(); ++it)
	{
		cout << it->first << " : ";
		it->second.print();
	}
}

void Multimap()
{
	multimap<int, string> lookup;

	lookup.insert(make_pair(30, "Vincent"));
	lookup.insert(make_pair(22, "yergtt"));
	lookup.insert(make_pair(45, "ASDF"));

	//multimap allows for duplicate keys
	for (multimap<int, string>::iterator it = lookup.begin(); it != lookup.end(); ++it)
	{
		cout << it->first << " : " << it->second << endl;
	}

	//to find a range of elements with the 
	pair<multimap<int, string>::iterator, multimap<int, string>::iterator> its = lookup.equal_range(30);
	for (multimap<int, string>::iterator it = its.first; it != its.second; ++it)
	{
		// 
	}

}

void trySet(){
	set<int> set;
	set.insert(4);
	set.insert(3);
	set.insert(1);

	for (auto const &value : set) {
		cout << value << endl;
	}
}

void TrySort() {
	vector<Person> persons;

	persons.push_back(Person("Vincent", 20));
	persons.push_back(Person("A", 12));
	persons.push_back(Person("X", 23));

	sort(persons.begin(), persons.end(), comp);
}

int main()
{
	//tryVector();
	//MultidimentionalVector();
	//tryList();
	//tryMap();
	//CustomMap();
	//Multimap();
	TryConstructors();
	//trySet();

	//werkt niet
	//TrySort();
	return 0;
}
