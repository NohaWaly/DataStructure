// heapUsingArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class MinHeap {
	int *heapArr; //pointer to array of elements in heap
	int capacity; //maximum size of heap
	int heapSize; //current size
public:
	void swap(int* x, int* y) {
		int temp = *x;
		*x = *y;
		*y = temp;
	}
	int parent(int i) {
		return (i - 1) / 2;
	}
	//get index of left child of node at index i
	int left(int i) {
		return (2 * i + 2);
	}
	//get index of right child of node at index i
	int right(int i) {
		return (2 * i + 2);
	}
	//return minmum key (key at root) from min heap
	int getmin() {
		return heapArr[0];
	}
	MinHeap(int cap) {
		heapSize = 0;
		capacity = cap;
		heapArr = new int[capacity];
	}
	void insertKey(int k) {
		if (heapSize == capacity) {
			cout << "can't insert more" << endl;
			return;
		}
		//1)insert the new key at the end
		heapSize++;
		int i = heapSize - 1;
		heapArr[i] = k;

		//2)fix the min heap property if there is a violation
		while (i != 0 && heapArr[parent(i)] > heapArr[i]) {
			swap(&heapArr[i], &heapArr[parent(i)]);
			i = parent(i);
		}

	}
	//dcreases value of key at index i to new val it is assumed that new val is smaller than heaparr[i]

	void decreasekey(int i, int newVal) {
		heapArr[i] = newVal;
		while (i != 0 && heapArr[parent(i)] > heapArr[i]) {
			swap(&heapArr[i], &heapArr[parent(i)]);
			i = parent(i);
		}
	}
	// a recursive method to heapify a subtree with root at given index

	void MiniHeapify(int i) {
		int L = left(i);
		int R = right(i);
		int smallest = i;
		if (L < heapSize && heapArr[L] < heapArr[i]) {
			smallest = L;
		}
		if (R < heapSize && heapArr[R] < heapArr[smallest]) {
			smallest = R;
		}
		if (smallest != i) {
			swap(&heapArr[i], &heapArr[smallest]);
			MiniHeapify(smallest);
		}
	}

	//remove minimum element from min heap (root)

	int extractMin() {
		if (heapSize <= 0) {
			return -1;
		}
		else if (heapSize == 1) {
			heapSize--;
			return heapArr[0];
		}
		//store the minimum value and remove it from heap
		int root = heapArr[0];
		heapArr[0] = heapArr[heapSize - 1];
		heapSize--;
		MiniHeapify(0);

		return root;
	}

	void deleteKey(int i) {
		decreasekey(i, INT_MIN);
		extractMin();
	}

};


int main()
{
	MinHeap h(11);
	h.insertKey(3);
	h.insertKey(2);
	h.deleteKey(1);
	h.insertKey(15);
	h.insertKey(5);
	h.insertKey(4);
	h.insertKey(45);
	cout << h.extractMin() << endl;
	cout << h.getmin() << endl;
	h.decreasekey(2, 1);
	cout << h.getmin() << endl;
    return 0;
}

