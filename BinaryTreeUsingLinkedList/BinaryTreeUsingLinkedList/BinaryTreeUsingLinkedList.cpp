// BinaryTreeUsingLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

struct node {
	int value;
	node *left;
	node *right;
};

	
	//function to create a new BST node
	node *newnode(int item) {
		node *root = new node;
		root->value = item;
		root->right = NULL;
		root->left = NULL;
		return root;
	}

	//function to traversal on BST
	void inorder(node *root) {
		if (root != NULL) {
			inorder(root->left);
			cout << root->value << endl;
			inorder(root->right);
		}
	}
	int counter = 0;
	int nodecount(node* root) {
		if (root != NULL) {
			nodecount(root->left);
			nodecount(root->right);
			counter++;
		}
		return counter;
	}
	//function to insert new node
	node *insert(node* node, int key) {
		if (node == NULL) //at the begining the tree is empty
		{
			return newnode(key);
		}
		if (key < node->value) {
			node->left = insert(node->left, key);
		}
		else if (key > node->value) {
			node->right = insert(node->right, key);
		}
        //return the unchanged node pointer
		return node;
	}


int main()
{
	node *root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);
	inorder(root);
	cout << nodecount(root) << endl;

    return 0;
}

