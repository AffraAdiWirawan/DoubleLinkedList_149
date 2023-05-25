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

void DoubleLinkedList::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student : ";
	cin >> nim;
	cout << "\nEnter the name of the student :";
	cin >> nm;
	node* newNode = new node(); // step 1
	newNode->noMhs = nim; // step 2
	newNode->name = nm; // step 2

	// insert a node in the beginning of a doubly - linked list
	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = START;  // step 3
		if (START != NULL)
			START->prev = newNode;
		newNode->prev = NULL;
		START = newNode;
		return;
	}
	//inserting a node between two nodes in the list
	node* current = START; // step 1.a
	node* previous = NULL; // step 1.b
	while (current->next && current->next->noMhs < nim) // step 1.c
	{
		previous = current; // 1.d
		current = current->next; //1.e
	}
	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}

	newNode->next = current->next; // step 4
	newNode->prev = current; // step 5
	if (current->next != NULL)
		current->next->prev = newNode; // step 6
	current->next = newNode; //step 7
}

bool DoubleLinkedList::search(int rollNo, node** previous, node** current) {
	*previous = START; // STEP 1.A
	*current = START;
	while (*current != NULL && rollNo != (*current)->noMhs) {
		*previous = *current;
		*current = (*current)->next;
	}
	return (*current != NULL);
}

bool DoubleLinkedList::deleteNode(int rollNo) {
	node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false)
		return false;
	if (current->next != NULL)
		current->next->prev = previous; //step 2
	if (previous != NULL)
		previous->next = current->next; //step 3
	else
		START = current->next;

	delete current; // step 4
	return true;
}

bool DoubleLinkedList::listEmpety() {
	return (START == NULL);
}

void DoubleLinkedList::traverse() {
	if (listEmpety())
		cout << "\nList is empty" << endl;
	else {
		cout << "\n in ascending of roll number are : " << endl;
		node* currentNode = START;
		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
	}
}

void DoubleLinkedList::revtraverse() {
	if (listEmpety()) {
		cout << "\nList is empty" << endl;
	}
	else cout << "\nRecords in descending orders of roll number are : " << endl;
	node* currentNode = START;
	while (currentNode->next != NULL)
		currentNode = currentNode->next;

	while (currentNode != NULL) {
		cout << currentNode->noMhs << " " << currentNode->name << endl;
		currentNode = currentNode->prev;
	}
}