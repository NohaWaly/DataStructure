// ListArrayBased.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "arrayList.h"

int main()
{
	arrayList arr(5);
	arr.insertAtEnd(5);
	arr.insertAt(1, 1);
	arr.print();
	
    return 0;
}

