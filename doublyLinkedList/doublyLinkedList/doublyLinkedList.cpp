// doublyLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
	node* prev;
};

class DoublyLinkedList {
public:
	node* head;
	node* tail;
	DoublyLinkedList() {
		head = NULL;
		tail = NULL;
	}
	void print() {
		node* current = head;
		while (current != NULL) {
			cout << current->data << " , ";
			current = current->next;
		}
		cout << endl;
	}
	void insertAtHead(int value) {
		node* temp = new node();
			temp->data = value;
			temp->prev = NULL;
			temp->next = head; //why next equals head?????
				if (head == NULL) //if list is empty 
				{
					head = temp;
					tail = temp;
				}
				else //the list isn't empty
					{
						head->prev = temp;
						head = temp;
					}
	}


	void insertAtTail(int value) {
		node* temp = new node();
		temp->data = value;
		temp->next = NULL;
		temp->prev = tail;
	
		if (head == NULL) {
			head = tail = temp;
		}
		else {
			tail->next = temp;
			tail = temp;
		}
	}

	void removeNode(int value) {
		node* curr = head;
		while (curr != NULL) {
			if (curr->data == value) {
				if (head->next == NULL) //only element
				{
					head = NULL;
					tail = NULL;
				}
				else if (curr->prev == NULL) //first element
				{
					head = head->next;
					head->prev = NULL;
				}
				else if (curr->next == NULL) //last element
				{
					tail = tail->prev;
					tail->next = NULL;
				}
				else //3adi fel nos
				{
					curr->prev->next = curr->next; //el element aly ablo( abl el current) 7at fel next bta3o el next bta3 el current
					curr->next->prev = curr->prev; //el element aly b3d el current 7at fel previous bta3o aly abl el current
				}
			}
			curr = curr->next;
		}
	}

};
int main()
{   
	//if you want to make it circular the next of the tail will pointer to head instead of NULL
	DoublyLinkedList list;
	list.insertAtHead(6);
	list.insertAtHead(3);
	list.insertAtTail(8);
	list.insertAtHead(2);
	list.insertAtHead(4);
	list.insertAtTail(9);
	list.print();
	list.removeNode(2);
	list.print();
    return 0;
}

