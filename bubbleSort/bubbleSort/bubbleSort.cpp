// bubbleSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int arr[10] = { 3,7,5,1,9,10,2,4,6,8 };
	int n = 10;
	for (int i = 0;i < n;i++){
		for (int j = 1;j < n;j++) {
			if (arr[j] < arr[j - 1]) {
				swap(arr[j], arr[j - 1]);
			}
		}
}
	for (int i = 0;i < 10;i++) {
		cout << arr[i] << " , ";
	}
    return 0;
}

