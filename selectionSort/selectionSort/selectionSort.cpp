// selectionSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int arr[10] = { 3,7,5,1,9,10,2,4,6,8 };
	int mini;
	for (int i = 0;i < 10;i++) {
		for (int j = i + 1;j < 10;j++) {
			mini = i;
			if (arr[j] < arr[mini]) {
				mini = j;
			}
			swap(arr[mini], arr[i]);
		}
		
		}
	for (int i = 0;i < 10;i++) {
		cout << arr[i] << " , ";
	}
    return 0;
}

