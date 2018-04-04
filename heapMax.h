#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::rand;

class HeapMax
{
	//implementation based on dynamic array 	
private:
	
	int *pointer;		// pointer to array of elements in heap
	int maxSize;		// maximum size of heap
	int currentSize;		// current size of heap

public:
	HeapMax();				// constructor, initializes all variables to 0
	HeapMax(int size);		// constructor, creates an array with max n elements
	//HeapMax(const HeapMax&);	//copying constructor
	int getCurrentSize();
	int getMaxSize();
	void printHeap();
	int parent(int i);
	int leftSon(int i);
	int rightSon(int i);
	void swap(int *x, int *y);		// function that swaps two elements
	int findValue(int val);
	void addElem(int k);
	void deleteElem(int k);		// function that deletes key stored at index i
	void deleteNode(int i);		// function that deletes node that stores the value of k
	int getElem(int i);		// function that gets the value of the element stored at index i
	int getNode(int k);		// function that gets the index of the node where vaue k is stored
	bool isThere(int k);		//function that checks is value k belongs to the heap

	//operators:

	const HeapMax operator+(const HeapMax & heap) const;		// overloaded operator for adding heaps
	const HeapMax operator-(const HeapMax & heap) const;		// overloaded operator for substracting duplicated values 
	int operator [](int i);									// operator for getting pointer to value stored at index i
	bool operator==(const HeapMax &heap) const;				// comparing size of two heaps and maximum value
	HeapMax operator=(const HeapMax& heap);			//assigment operator

	~HeapMax();		//destructor
};

