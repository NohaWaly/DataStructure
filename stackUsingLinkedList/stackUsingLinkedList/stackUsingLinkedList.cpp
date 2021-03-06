// stackUsingLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct node {
	int value;
	node* next;
};

class stack {
public:
	node* head;
	node* current;
	int counter;
	int size;
	stack() {
		head = NULL;
		counter = 0;
	}
	stack(int v, int intialSize) {
		node* temp = new node;
		temp->value = v;
		temp->next = NULL;
		head = temp;
		current = head;
		for (int i = 0;i < intialSize;i++) {
			node* temp = new node;
			temp->value = v;
			temp->next = NULL;
			current->next = temp;
		}
	}

	int top() {
		current = head;
		while (current->next != NULL) {
			current = current->next;
		}
		return current->value;
	}

	void pop() {
		current = head;
		node* pervious = new node;
		while (current->next != NULL) {
			pervious = current;
			current = current->next;
		}
		pervious->next = NULL;
	}
	void push(int key) {
		while (current->next != NULL) {
			current = current->next;
		}
		node* temp = new node;
		temp->value = key;
		temp->next = NULL;
		current->next = temp;
	}
	~stack()
	{
		while(current != NULL)
		{
			current = head->next;
			delete[] head;
			head = current;
			
		}
	}
};

int main()
{
	stack mystack(3, 3);
	cout << mystack.top() << endl;
	mystack.push(2);
	mystack.push(4);
	mystack.push(5);
	cout << mystack.top() << endl;
	mystack.pop();
	cout << mystack.top() << endl;
    return 0;
}

