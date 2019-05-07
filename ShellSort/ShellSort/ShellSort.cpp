// ShellSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int arr[11] = { 46,2,83,41,102,6,17,31,64,49,18 };
	int ArrSize=11, temp;
	for (int gap=ArrSize/2;gap > 0;gap/=2) {
		for (int i = gap;i < ArrSize;i++) {
			temp = arr[i];
			int j = i;
			for (;j >= gap && (temp < arr[j - gap]) ;j -= gap) {
					arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}
	for (int i = 0;i < 11;i++) {
		cout << arr[i] << " , ";
	}
    return 0;
}

