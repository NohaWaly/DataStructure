// BracketDelimiter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	stack<int>list;
	string word;
	cout << "enter the word" << endl;
	cin >> word; //enter without spcaes
	for (int i = 0;i < word.length();i++) {
		if (word[i] == '(' || word[i] == '{' || word[i] == '[') //opening 
		{
			list.push(word[i]);
		}
		else if (word[i] == '/') {
			if (word[i + 1] == '*' && (i+1)!= word.length()) {
				list.push(word[i + 1]);
				list.push(word[i]);

			}
		}
	
		if (word[i] == ')' || word[i] == '}' || word[i] == ']') 
		{
			cout << list.top() << endl;
			list.pop();
		}
		else if (word[i] == '*') {
			if (word[i + 1] == '/' && (i + 1) != word.length()) //this gonna print */ 
			{
				cout << list.top() << endl;
				list.pop();
				cout << list.top() << endl;
				list.pop();
			}
		}
		else //normal character
		{
			continue; //break this iteration and but continue on loop
		}
		
	}
    return 0;
}

