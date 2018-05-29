#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <list>
#include <map>
//vector is resizable
using namespace  std;

void tryVector()
{
	//presize vector door (x) (kan, hoeft niet)
	vector<string> strings;

	strings.push_back("hello");
	strings.push_back("asdf");
	strings.push_back("sdfg");

	for(int i=0; i<strings.size(); i++)
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
	vector<vector<int> > grid(3,vector<int>(4,0));

	grid[1].push_back(8);

	for(int row = 0; row < grid.size(); row ++)
	{
		string a= "";

		for(int col =0; col < grid[row].size(); col++)
		{
			grid[row][col] = col * 12;
			a += std::to_string(grid[row][col]);
		}
		cout << a << endl;
	}

}

// double linked list
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
	pair<string, int> vincentAge = { "Vincent", 23 };

	ages.insert(vincentAge);

	// de iterator point naar een pair van hetzelfde type als de map (map = een list van pairs)
	for (map<string, int>::iterator it = ages.begin(); it != ages.end(); ++it)
	{
		pair<string, int> age = *it;
	}


	for(map<string, int>::iterator it = ages.begin(); it != ages.end(); ++it)
	{
		cout << it ->first << " is" << it ->second << endl;
	}

	if(ages.find("Vicky")!= ages.end())
	{
		//checken of er een item in de map aanwezig is
	}
}


int main()
{	
	//tryVector();
	//MultidimentionalVector();
	//tryList();
	tryMap();
}
