#include <iostream>
#include "Heap.h"

using namespace std;

int Heap::Left(int node)
{
	return 2*node +1;
}

int Heap::Right(int node)
{
	return 2 * node + 2;
}

int Heap::Parent(int node)
{
	return (node - 1) / 2;
}

void Heap::Swap(int p1, int p2) {
	Person *temp = data[p1];
	data[p1] = data[p2];
	data[p2] = temp;
}

void Heap::FixHeap(int node)
{
	int min;
	int left = Left(node);
	int right = Right(node);

	if (left < heapSize && data[left]->id < data[node]->id)
		min = left;
	else
		min = node;

	if (right < heapSize && data[right]->id < data[min]->id)
		min = right;


	if (min != node) {
		Swap(min, node);
		FixHeap(min);
	}
}

Heap::Heap(int max)
{
	data = new Person*[max];
	maxSize = max;
	heapSize = 0;
	allocated = 1;
}

Heap::Heap(Person * P[], int n)
{
	heapSize = maxSize = n;
	data = P;
	allocated = 0;
	for (int i = n / 2 - 1; i >= 0; i--)
		FixHeap(i);
}

Heap::~Heap()
{
	delete data;
}

Person * Heap::Min()
{
	return data[0];
}

Person * Heap::DeleteMin()
{
	if (heapSize < 1)
	{
		cout << "Heap Size err" << endl;
		exit(1);
	}

	Person *min = data[0];
	heapSize--;
	data[0] = data[heapSize];
	FixHeap(0);

	return min;
}

void Heap::Insert(Person * item)
{
	if (heapSize == maxSize)
	{
		cout << "heap size err" << endl;
		exit(1);
	}

	int i = heapSize;
	heapSize++;
	while ((i > 0) && (data[Parent(i)]->id < item->id))
	{
		data[i] = data[Parent(i)];
		i = Parent(i);
	}
	data[i] = item;
}
