#include "stdafx.h"
#include "arrayList.h"


arrayList::arrayList(int size)
{
	if (size < 0) {
	   cout << "size must be positive, initially size of array equals 100" << endl;
	   maxSize = 100;
	}
	else {
		maxSize = size;
	}
	length = 0;
	list = new int[maxSize];
}

arrayList::arrayList()
{
	maxSize = 100;
	length = 0;
	list = new int[maxSize];
}

arrayList::arrayList(const arrayList& original)
{
	maxSize = original.maxSize;
	length = original.maxSize;
	list = new int[maxSize];
	for (int i = 0;i < length;i++) {
		list[i] = original.list[i];
	}
}

bool arrayList::isEmpty(){
	return (length == 0);
}

bool arrayList::isFull()
{
	return (length == maxSize);
}

int arrayList::listSize() {
	return length;
}

int arrayList::maxlistSize() {
	return maxSize;
}

void arrayList::print() {
	for (int i = 0;i < length;i++) {
		cout << list[i] << " ";
	}
	cout << endl;
}

bool arrayList::isItemAtEqual(int location, int& item) {
	return (list[location] == item);
 }

void arrayList::insertAt(int location, int item) {
	if (location < 0 || location >= maxSize) {
		cout << "can't insert in a full list" << endl;
	}
	else {
		for (int i = length; i > location;i--) {
			list[i] = list[i - 1]; //shift right till location
		}
		list[location] = item;
		length++;
	}
}

void arrayList::insertAtEnd(int item) {
	if (length < 0 || length >= maxSize) {
		cout << "can't insert in a full list" << endl;
	}
	else {
		list[length] = item;
		length++;
	}
}

void arrayList::removeAt(int location) {
	if (location < 0 || location >= maxSize) {
		cout << "out of range" << endl;
	}
	else {
		for (int i = location; i < length - 1;i++) {
			list[i] = list[i + 1];
		}
		length--;
	}
}

int arrayList::retreiveAt(int location) {
	if (location < 0 || location >= maxSize) {
		cout << "out of range" << endl;
	}
	else {
		return list[location];
	}
}

void arrayList::clearList() {
	length = 0;
}

arrayList& arrayList::operator=(const arrayList& otherlist) {
	if (this != &otherlist) {
		delete[] list;
		maxSize = otherlist.maxSize;
		length = otherlist.length;
		list = new int[maxSize];
		for (int i = 0;i < length;i++) {
			list[i] = otherlist.list[i];
		}
	}
	return *this;
}

int arrayList::seqSearch(int& item) {
	int i;
	bool found = false;
	for (i = 0;i < length;i++) {
		if (list[i] == item) {
			found = true;
			break;
		}
	}
	if (found) {
		return i;
	}
	else
		return -1;
}

void arrayList::insert(int& item) {
	int loc;
	if (length == 0) {
		list[length++] = item;
	}
	else if (isFull()) {
		cout << "is full" << endl;
	}
	else {
		loc = seqSearch(item);
		if (loc == -1) {
			list[length++] = item;
		}
		else {
			cout << "already exist no duplicate" << endl;
		}
	}
}

void arrayList::remove(int& item) {
	int loc;
	if (length == 0) {
		cout << "can't delete from empty list" << endl;
	}
	else {
		loc = seqSearch(item);
		if (loc == -1) {
			removeAt(loc);
		}
		else {
			cout << "the item doesn't exist" << endl;
		}
	}
}

arrayList::~arrayList()
{
	delete[] list;
}
