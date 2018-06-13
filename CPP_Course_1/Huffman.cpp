// C++ program for Huffman Coding
#pragma once
#include "stdafx.h"
//#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <sstream>
#include <map>
using namespace std;

//https://planetcalc.com/2481/
// A Huffman tree node
struct MinHeapNode {

	// One of the input characters
	char data;

	// Frequency of the character
	unsigned freq;

	// Left and right child
	MinHeapNode *left, *right;

	MinHeapNode(char data, unsigned freq)
	{
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};
struct HuffmanInfo
{
	vector<char> characters;
	vector<int> integers;
};

HuffmanInfo DeconstructString(string str)
{
	map<char, int> map1;

	for (auto i = 0; i < str.size(); ++i)
	{
		char c = str.at(i);
		auto j = map1.find(c);
		if (j == map1.end())
		{
			map1.insert({ c, 1 });
		}
		else {
			pair<char, int> pair = *j;
			pair.second++;
			map1.at(c) = pair.second;
		}
	}
	HuffmanInfo info;

	for (map<char, int>::iterator it = map1.begin(); it != map1.end(); ++it)
	{
		pair<char, int> combo = *it;
		info.characters.push_back(combo.first);
		info.integers.push_back(combo.second);
	}
	return info;
}

// For comparison of
// two heap nodes (needed in min heap)
struct compare {

	bool operator()(MinHeapNode* l, MinHeapNode* r)

	{
		return (l->freq > r->freq);
	}
};

// Prints huffman codes from
// the root of Huffman Tree.
void printCodes(struct MinHeapNode* root, string str)
{
	if (!root)
		return;
	string result;
	stringstream s(result);
	if (root->data != '$') {
		s << root->data;
		s << ": ";
		s << str;
		s << "\n";
	}
	cout << s.str();


	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
	
}


// The main function that builds a Huffman Tree and
// print codes by traversing the built Huffman Tree
void HuffmanCodes(char data[], int freq[], int size)
{
	struct MinHeapNode *left, *right, *top;

	// Create a min heap & inserts all characters of data[]
	std::priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

	for (int i = 0; i < size; ++i)
		minHeap.push(new MinHeapNode(data[i], freq[i]));

	// Iterate while size of heap doesn't become 1
	while (minHeap.size() != 1) {

		// Extract the two minimum
		// freq items from min heap
		left = minHeap.top();
		minHeap.pop();

		right = minHeap.top();
		minHeap.pop();

		// Create a new internal node with
		// frequency equal to the sum of the
		// two nodes frequencies. Make the
		// two extracted node as left and right children
		// of this new node. Add this node
		// to the min heap '$' is a special value
		// for internal nodes, not used
		top = new MinHeapNode('$', left->freq + right->freq);

		top->left = left;
		top->right = right;

		minHeap.push(top);
	}

	// Print Huffman codes using
	// the Huffman tree built above
	printCodes(minHeap.top(), "");
}

// Driver program to test above functions
int main8()
{

	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	int freq[] = { 5, 9, 12, 13, 16, 45 };

	int size = sizeof(arr) / sizeof(arr[0]);

	HuffmanCodes(arr, freq, size);

	return 0;
}