// QuickSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
//template <class T>
////utility function to swap two elements
//void swap(T *a, T *b) {
//	T temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
///*this function takes last element as a pivot, places the pivot element at its correct position in sorted array and places all smaller to left and all greater to right*/
//template <class T>
//int partition(T arr[], int low, int high) {
//	int pivot = arr[high]; //pivot
//	int i = low - 1;
//	for (int j = low;j <= high - 1;j++) {
//		if (arr[j] <= pivot) {
//			i++; //increament index of smaller element
//			swap(&arr[i], &arr[j]);
//		}
//	}
//	swap(&arr[i], &arr[high]);
//	return (i + 1);
//}
//template <class T>
//void quickSort(T arr[], int low, int high) {
//	if (low < high) {
//		int pivot = partition(arr, low, high);
//		//separately sort element before and after partition
//		quickSort(arr, low, pivot - 1);
//		quickSort(arr, pivot + 1, high);
//	}
//}

int main()
{
	int arr[6] = { 10,7,8,9,1,5 };
	//quickSort<int>(arr, 0,5);
	for (int i = 0;i < 6;i++) {
		cout << arr[i] << " , ";
	}
    return 0;
}

