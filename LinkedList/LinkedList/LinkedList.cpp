// LinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
struct node {
	int data;
	node *next;
};

class linkedList {
public:
	node *head;
	node *current;
	node *A;
	node *B;
	int count;
	linkedList() {
		head = NULL;
		count = 0;
	}
	void addAtEnd(int value) {
		if (head == NULL) {
			node *temp = new node;
			temp->data = value;
			temp->next = NULL;
			head = temp; //head points to the node which called temp 		
		}
		else {
			current = head;
			while (current->next != NULL) {
				current = current->next;
			}
			node *temp = new node;
			temp->data = value;
			temp->next = NULL;
			current->next = temp;
		}
		
		count++;
  }

	void print() {
		current = head;
		while (current != NULL){
			cout << current->data << " , ";
			current = current->next;
		} 
		cout << endl;
	}

	int length() {
		return count;
	}

	bool search(int key) {
		current = head;
		while (current != NULL) {
			current = current->next;
			if (current->data == key) {
				return true;
			}
		}
		return false;
	}

	void deleteNode(int key) {
	  node* cur;
	  cur = head;
	  node* per = new node;
	  while (cur != NULL) //this while prevent condition 1)list is empty 2)element doesn't exist(lma ywsal lel akher w myl2hash)
	  {
		if (cur->data != key) {
			  per = cur;
			  cur = cur->next;
		  }
		 else{
			  if (head->data == key) {
				  head = cur->next;
				  break;
			}
			 else {
				  per->next = cur->next;
				  break;
			  }
		   
		     } 
	    }	
	}

};

int main()
{
	linkedList list;
	list.addAtEnd(4);
	list.addAtEnd(8);
	//list.print();
	list.addAtEnd(2);
	list.addAtEnd(3);
	list.addAtEnd(5);
	list.addAtEnd(6);
	list.print();

	cout << list.length() << endl;
	if (list.search(6)) {
		cout << "found" << endl;
	}
	else {
		cout << "not found" << endl;
	}
	list.deleteNode(3);
	list.print();

    return 0;
}

