#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <mutex>
using namespace std;

void writeData(string data[])
{
	fstream outstream;
	string const inFileName = "Test.txt";
	outstream.open(inFileName, ios::out);
	for (auto i =0; i < data->length(); i++ )
	{
		outstream << data[i] << endl;
	}
	outstream.close();
}


vector<string> readData() 
{
	fstream instream;
	instream.open("Test.txt", ios::in);
	vector<string> output;
	string line;

	while(instream)
	{
		getline(instream, line);
		output.push_back(line);
	}
	output.pop_back();
	return output;
}

int main2 ()
{
	string data[] = { "one", "two", "three" };
	writeData(data);
	vector<string> fileData = readData();
	for (auto const& value : fileData)
	{
		cout << value << endl;
	}
	return 0;	
}