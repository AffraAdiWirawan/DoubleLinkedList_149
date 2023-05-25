#include <iostream>
#include <string>

using namespace std;

class node {
public:
	int noMhs;
	string name;
	node* next;
	node* prev;
};

class DoubleLinkedList {
private:
	node* START;
public:
	DoubleLinkedList();
	void addNode();
	bool search(int rollNo, node** previous, node** current);
	bool deleteNode(int rollNo);
	bool listEmpety();
	void traverse();
	void revtraverse();
	void hapus();
	void SearchData();
};

DoubleLinkedList::DoubleLinkedList() {
	START = NULL;
}
