// StackAddInt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> sd;
	int number = 23;
	while (number > 0)
	{
		int digit = number % 10;
		number /= 10;
		sd.push(digit);
	}

	while (!sd.empty())
	{
		//int digit = sd.front();
		cout << sd.top()<<endl;
		sd.pop();
	}
    return 0;
}

