#include "stdafx.h"
#include <fstream>
#include <vector>
#include <iostream>
//pragma pack voor het tegevgaan van de structpadding, anders kan de struct niet goed geserialised worden.
#pragma pack(push,1)
struct Person
{
	char name[50];
	int age;
	double weight;
};
#pragma pack(pop)

void writePersonsToFile(std::vector<Person> persons)
{
	std::ofstream output;
	output.open("persons.bin", std::ios::binary);
	
	if(output.is_open())
	{
		for(auto &value:persons)
		{
			//write verwacht een char* maar het is een struct dus daarom een cast
			output.write(reinterpret_cast<char*> (&value), sizeof(Person));
		}
		output.close();
	}
}

void ReadPersonsFromFile()
{
	std::ifstream input;
	input.open("persons.bin", std::ios::binary);

	Person somebody{};
	while(input.is_open())
	{
		input.read(reinterpret_cast<char*> (&somebody), sizeof(Person));
		std::cout << somebody.age << std::endl;

		// ook whitespace lezen anders ziet hij de laatste regel 2x
		input >> std::ws;
		if (input.eof())
			input.close();
	}
	
}

int main3()
{
	std::vector<Person> persons = { {"Vincent", 22, 100.0}, {"Bart", 21, 105} };
	writePersonsToFile(persons);

	ReadPersonsFromFile();

	return 0;
}
