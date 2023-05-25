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

void DoubleLinkedList::hapus() {
	if (listEmpety()) {
		cout << "\nList is empty" << endl;
	}
	node* prev, * curr;
	prev = curr = NULL;
	cout << "\nEnter the roll number of the student whose record you want to search :";
	int num;
	cin >> num;
	if (DoubleLinkedList::search(num, &prev, &curr) == false)
		cout << "\nRecord not found" << endl;
	else {
		cout << "\nRecord Found" << endl;
		cout << "\nRoll number : " << curr->noMhs << endl;
		cout << "\nName : " << curr->name << endl;
	}
}

void DoubleLinkedList::SearchData() {
	if (listEmpety() == true) {
		cout << "\nlist is empty" << endl;
	}
	node* prev, * curr;
	prev = curr = NULL;
	cout << "\nEnter the roll number of the student whose record you want to search : ";
	int num;;
	cin >> num;
	if (DoubleLinkedList::search(num, &prev, &curr) == false)
		cout << "\nRecord nof found" << endl;
	else {
		cout << "\nRecord found" << endl;
		cout << "\nRoll number :" << curr->noMhs << endl;
		cout << "\nName :" << curr->name << endl;
	}
}

int main() {
	DoubleLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all records in the ascending order of roll numbers" << endl;
			cout << "4. View all records in the descending order of roll numbers" << endl;
			cout << "5. Search fot a record in the list" << endl;
			cout << "6. Exit" << endl;
			cout << "\nEnter your choice(1-6) : " << endl;
			char ch;
			cin >> ch;
			switch (ch) {
			case '1':
				obj.addNode();
				break;
			case '2':
				obj.hapus();
				break;
			case '3':
				obj.traverse();
				break;
			case '4':
				obj.revtraverse();
				break;
			case '5':
				obj.SearchData();
				break;
			case '6':
				return 0;
			default:
				cout << "\nInvalid option" << endl;
				break;
			}
		}
		catch (exception& e) {
			cout << "Check for the values entered." << endl;
		}
	}
}