#pragma once
#include "Person.h"

class Heap
{
private:
	Person ** data;
	int maxSize;
	int heapSize;
	int allocated;
	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	void FixHeap(int node);
public:
	Heap(int Max);
	Heap(Person * A[], int n);
	~Heap();
	void Swap(int p1, int p2);
	Person * Min();
	Person * DeleteMin();
	void Insert(Person * item);

};

