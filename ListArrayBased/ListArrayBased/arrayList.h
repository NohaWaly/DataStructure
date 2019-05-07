#include <iostream>
using namespace std;

class arrayList
{
public:
	int length;
	int maxSize;
	int *list;
	bool isEmpty();
	bool isFull();
	int listSize();
	int maxlistSize();
	void print();
	bool isItemAtEqual(int, int&);
	void insertAt(int, int);
	void insertAtEnd(int);
	void removeAt(int);
	int retreiveAt(int);
	void clearList();
	int seqSearch(int&);
	void insert(int&);
	void remove(int&);
	arrayList(int = 100);
	arrayList(const arrayList&);
	arrayList();
	arrayList& operator=(const arrayList&);
	~arrayList();
};

