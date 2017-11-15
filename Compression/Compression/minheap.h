#ifndef MINHEAP_H
#define MINHEAP_H

#pragma execution_character_set("utf-8")

#define DefaultSize 256

#include <cassert>
#include <iostream>
#include <string>
using namespace std;

template <class E>
class MinHeap
{
public:
	MinHeap(int sz = DefaultSize);
	MinHeap(E arr[], int n);
	bool Insert(E& x);
	bool RemoveMin(E& x);
	bool IsEmpty()const
	{
		return (currentSize == 0) ? true, false;
	}
	bool IsFull()const
	{
		return (currentSize == maxHeapSize) ? true, false;
	}
	void MakeEmpty(){ currentSize = 0 };
private:
	E *heap;
	int currentSize;
	int maxHeapSize;
private:
	void siftDown(int start, int tn);
	void siftUp(int start);
};

template <class E>
MinHeap<E>::MinHeap(int sz)
{
	maxHeapSize = (DefaultSize < sz) ? sz : DefaultSize;
	heap = new E[maxHeapSize];
	if (heap == NULL)
		exit(1);
	currentSize = 0;
}

template <class E>
MinHeap<E>::MinHeap(E arr[], int n)
{
	maxHeapSize = (DefaultSize < n) ? n : DefaultSize;
	heap = new E[maxHeapSize];
	if (heap == NULL)
		exit(1);
	for (int i = 0; i < n; i++)
	{
		heap[i] = arr[i];
	}
	currentSize = n;
	int currentPos = (currentSize - 2) / 2;
	while (currentPos >= 0)
	{
		siftDown(currentPos, currentSize - 1);
		currentPos--;
	}
}

template <class E>
void MinHeap<E>::siftDown(int start, int m)
{
	int i = start;
	int j = 2 * i + 1;
	E temp = heap[i];
	while (j <= m)
	{
		if (i<m&&heap[j]>heap[j + 1])
			j++;
		if (temp <= heap[j])
			break;
		else{
			heap[i] = heap[j];
			i = j;
			j = 2 * j + 1;
		}
	}
	heap[i] = temp;
}

template <class E>
void MinHeap<E>::siftUp(int start)
{
	int j = start;
	int i = (j - 1) / 2;
	E temp = heap[j];
	while (j > 0)
	{
		if (heap[i] <= temp)
			break;
		else{
			heap[j] = heap[i];
			j = i;
			i = (i - 1) / 2;
		}
	}
	heap[j] = temp;
}

template <class E>
bool MinHeap<E>::Insert(E& x)
{
	if (currentSize == maxHeapSize)
		return false;
	heap[currentSize] = x;
	siftUp(currentSize);
	currentSize++;

	return true;
}

template <class E>
bool MinHeap<E>::RemoveMin(E &x)
{
	if (!currentSize)
		return false;
	x = heap[0];
	heap[0] = heap[currentSize - 1];
	currentSize--;
	siftDown(0, currentSize - 1);

	return true;
}

#endif