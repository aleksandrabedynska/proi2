#include "heapMax.h"

int main()
{
	int sizeCheck;
	int node;
	int value;
	srand(time(NULL));
	HeapMax heap(7);
	while (heap.getCurrentSize() < heap.getMaxSize())
	{
		heap.addElem(rand() % 20);
	}
	heap.printHeap();

	heap.getElem(1);
	heap.getNode(1);
	heap.isThere(15);

	HeapMax heap2(5);
	while (heap2.getCurrentSize() < heap2.getMaxSize())
	{
		heap2.addElem(rand() % 20);
	}
	heap2.printHeap();
	/*
	heap.printHeap();
	sizeCheck = heap.getCurrentSize();
	cout << "current size is " << sizeCheck << endl;
	heap.deleteNode(2);
	heap.printHeap();
	sizeCheck = heap.getCurrentSize();
	cout << "current size is " << sizeCheck << endl;
	heap.addElem(15);
	heap.printHeap();
	sizeCheck = heap.getCurrentSize();
	cout << "current size is " << sizeCheck << endl;
	node=heap.findValue(15);
	cout << "node where the value is stored  is: " << node <<"	*If it's -1 then no such value was found*"<< endl;
	/*
	heap.deleteElem(15);
	heap.printHeap();
	sizeCheck = heap.getCurrentSize();
	cout << "current size is " << sizeCheck << endl;
	*/
	

	HeapMax heap3 = heap + heap2;
	heap3.printHeap();
	//cout << heap3.getMaxSize() << endl;
	cout << "current size of heap 3 is " << heap3.getCurrentSize() << endl;
	cout << "operator [2] test :" << heap3[2] << endl;
	/*int s= heap3.getCurrentSize();
	cout << s;
	*/
	bool isIt = heap == heap2;
	cout << "test == operator " << isIt << endl;

	/*HeapMax heap4;
	//cout << "copying constructor test: " << endl;
	//heap4.printHeap();
	heap4 = heap2;
	cout << "assignment operator test: " << endl;
	heap4.printHeap();

	*/
	
	
	
	return 0;
}