// QueueUsingLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct node{
	int value;
	node* next;
};

class Queue{
public:
	node * head;
	node * current;
	int size;
	Queue() {
		head = NULL;
		size = 0;
	}

	Queue(int v, int initial_size) {
		node* temp = new node;
		temp->value = v;
		temp->next = NULL;
		head = temp;
		current = head;
		size = 0;
		for (int i = 0;i < initial_size;i++) {
			node* temp = new node;
			temp->value = v;
			temp->next = NULL;
			current->next = temp;
			size++;
		}
	}

	~Queue()
	{
		while (current != NULL) {
			current = head->next;
			delete[] head;
			head = current;
		}
	}

	int front() {
		return head->value;
	}

	void pop() {
		head = head->next;
	}
	void push(int v) {
		node* temp = new node;
		temp->value = v;
		temp->next = NULL;
		current = head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = temp;
		size++;
	}

	int QueueSize() {
		return size;
	}
};
int main()
{
	Queue myQueue(2,2);
	cout << myQueue.front() << endl;
	myQueue.push(3);
	myQueue.push(4);
	myQueue.push(5);
	myQueue.push(6);
	cout << myQueue.front() << endl;
	myQueue.pop();
	cout << myQueue.front() << endl;
	myQueue.pop();
	cout << myQueue.front() << endl;
    return 0;
}

