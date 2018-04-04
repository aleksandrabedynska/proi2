#include "heapMax.h"

HeapMax::HeapMax()
{
	currentSize = 0;
	maxSize = 0;
	pointer = new int[maxSize];
}

HeapMax::HeapMax(int size)
{
	currentSize = 0;
	maxSize = size;
	pointer = new int[maxSize];
}

/*HeapMax::HeapMax(const HeapMax &)
{
}
*/
int HeapMax::getCurrentSize()
{
	return currentSize;	
}

int HeapMax::getMaxSize()
{
	return maxSize;
}

void HeapMax::printHeap()
{
	cout << "value" << " " << "node no" << endl;
	for (int i = 0; i < currentSize; i++)
	{
		cout << pointer[i] << "	" << i << endl;
	}

}

int HeapMax::parent(int i)
{
	return (i-1)/2;
}

int HeapMax::leftSon(int i)
{
	return (2*i+1);
}

int HeapMax::rightSon(int i)
{
	return (2*i+2);
}

void HeapMax::swap(int * x, int * y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int HeapMax::findValue(int val)
{
	int temp = -1;		//temporary variable to exit loop
	for (int i = 0; i < currentSize; i++)
	{
		if (pointer[i] == val) 
			temp = i;
		
	}
	if (temp == -1) {
		cout << "Value "<< val << " not found." << endl;
		return -1;
	}
	else
		return temp;

	
}
void HeapMax::addElem(int k)
{
	if (currentSize < maxSize)
	{
		currentSize++;
		int i = currentSize - 1;
		pointer[i] = k;

		while (i != 0 && pointer[i] > pointer[parent(i)])
		{
			swap(&pointer[parent(i)], &pointer[i]);
			i = parent(i);
		}
	}
	else
		cout << "Heap Overflow, not enough space" << endl;
}

void HeapMax::deleteElem(int k)
{
	int nodeToDelete = findValue(k);
	if (nodeToDelete == -1)
		cout << "Value" << k <<" not found." << endl;
	else
		deleteNode(nodeToDelete);
}

void HeapMax::deleteNode(int i)
{
	pointer[i] = pointer[currentSize - 1];
	currentSize--;
	while (pointer[i] > pointer[parent(i)])
	{
		swap(&pointer[parent(i)], &pointer[i]);
		i = parent(i);
	}

	while (leftSon(i)<currentSize && pointer[i] > pointer[leftSon(i)])
	{
		swap(&pointer[leftSon(i)], &pointer[i]);
		i = leftSon(i);
	}
	while (rightSon(i)<currentSize && pointer[i] > pointer[rightSon(i)])
	{
		swap(&pointer[rightSon(i)], &pointer[i]);
		i = rightSon(i);
	}
}

int HeapMax::getElem(int i)
{
	if (i > currentSize)
	{
		cout << "Index out of range, no such node" << endl;
		return -1;
	}
		
	else
	{
		cout << "value stored at node "<< i<< " is " << pointer[i] << endl;
		return pointer[i];
		
	}
}

int HeapMax::getNode(int k)
{
	int temp=findValue(k);
	cout << "node at which value " << k << " is stored is " << temp << endl;
	return temp;
}

bool HeapMax::isThere(int k)
{
	int temp;
	temp = findValue(k);
	if (temp == -1)
		return false;
	else 
	{
		cout << "Value "<< k << " belongs to a heap" << endl;
		return true;
	}
		
}

const HeapMax HeapMax::operator+(const HeapMax & heap) const
{
	HeapMax result;
	result.maxSize = maxSize + heap.maxSize;
	result.currentSize = 0;
	for (int i = 0; i < currentSize; i++)
	{
		result.pointer[i] = pointer[i]; 
		result.currentSize++;
		
	}
	for (int i = 0; i < heap.currentSize; i++)
	{
		result.addElem(heap.pointer[i]);
		
	}
	
	return result;
}

const HeapMax HeapMax::operator-(const HeapMax & heap) const
{





	return HeapMax();
}

int HeapMax::operator[](int i)
{
	int result = getElem(i);
	return result;
}

bool HeapMax::operator==(const HeapMax & heap) const
{

	if (heap.currentSize == currentSize && heap.pointer[0] == pointer[0])
	{
		cout << "These two heaps have the same size & maximum value at node no 0" << endl;
		return true;
	}
	else
		if (heap.currentSize == currentSize && heap.pointer[0] != pointer[0])
		{
			cout<< "These two heaps only have the same size" << endl;
			return false;
		}
		else
			if (heap.currentSize != currentSize && heap.pointer[0] == pointer[0])
			{
				cout << "These two heaps only have the same maximum value at node no 0" << endl;
				return false;
			}
			else
				return false;
}

HeapMax HeapMax::operator=(const HeapMax & heap)
{
	
	if (this != &heap)
	{
		delete [] pointer;
		pointer = new int[heap.maxSize];
		for (int i = 0; i < heap.maxSize; i++)
		{
			pointer[i] = heap.pointer[i];
			cout << pointer[i];
		}
		maxSize = heap.maxSize;
	}
		return *this;

}



HeapMax::~HeapMax()
{
}
