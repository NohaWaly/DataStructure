// mergeSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void merge(int arr[], int left, int middle, int right) {
	//divide the array two halves
	int leftArrSize = middle - left + 1;
	int rightArrSize = right - middle;
	int *leftarr= new int[leftArrSize];
	int *rightarr = new int[rightArrSize];

		//assiging values to arrays
		for (int i = 0;i < leftArrSize;i++) {
			leftarr[i] = arr[left + i];
		}
		for (int j = 0;j < rightArrSize;j++) {
			rightarr[j] = arr[middle + j+1];
		}

		// merge the two arrys again in a sorted way
		int k = left, i = 0, j = 0;
		while (i < leftArrSize && j < rightArrSize) {
			if (leftarr[i] < rightarr[j]) {
				arr[k++] = leftarr[i++];
			}
			else {
				arr[k++] = rightarr[j++];
			}
		}

		//complete puting elements if on of two arrays has finished before the other
		while (i < leftArrSize) {
			arr[k++] = leftarr[i++];
		}
		while (j < rightArrSize) {
			arr[k++] = rightarr[j++];
		}

}

void mergeSort(int arr[],int left, int right) {
	int mid = (left + right) / 2;
	if (left < right) {
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

int main()
{
	int arr[10] = { 3,5,6,9,1,2,10,8,7,4 };
	mergeSort(arr, 0, 9);
	for (int i = 0;i < 10;i++) {
		cout << arr[i] << " , ";
	}
    return 0;
}

