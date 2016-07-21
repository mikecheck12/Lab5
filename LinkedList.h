#pragma once
#include <iostream>

template <typename ItemType>

class LinkedList {

private:

	//Node* temp;
	//int count;
	//Linked List Constructor
	//LinkedList(Node* head = NULL, Node* tail = NULL, int size = 0) : head(head), tail(tail), size(size) {}

	struct Node {
		ItemType item;
		Node* next;
		Node* prev;
		//Constructor Node(data, next, prev)
		Node(const ItemType& data, Node* nextVal = NULL, Node* prevVal = NULL) : item(data), next(nextVal), prev(prevVal) {}
		//Destructor
		~Node() {};
	};

	Node* head;
	Node* tail;
	int size;


public:
	// List constructor
	LinkedList() {
		head = NULL;
		tail = NULL;
		size = 0;
	}

	//List Destructor
	~LinkedList() {};


//Clear function
	void clear(){
			while (head != NULL) {
				Node* current = head;
				head = head->next;
				delete current;
			}
			tail = NULL;
			size = 0;
			cout << "clear" << endl;
	}

//Initial Item
	void startList(const ItemType& item) {
		head = new Node(item, NULL, NULL);
		tail = head;
		size++;
	}

//insert items to front of list
	void push_front(const ItemType& item) {
		if (size == 0) {
			startList(item);
		}
		else {
			//head = new Node(item, NULL, head);
			head = new Node(item, head, NULL);

			if (head->next != NULL) {
				head->next->prev = head;
				size++;
			}
			//if (tail == NULL) {
				//tail = head;
				//size++;
			//}
		}
	}
//insert items on back of list
	void push_back(const ItemType& item) {
		if (tail != NULL) {
			tail->next = new Node(item, NULL, head);
			tail = tail->next;
			size++;
		}
		else {
			push_front(item);
		}
	}

//insert items inside the list
	void insert(int index, const ItemType& item) {
		
		int count = 0;
		Node* temp = head;

		cout << "insert " << index << " " << item << endl;

		if (index < 0 || index > size) {
			//not valid
			return;
		}
		else {
			while (count != index) {
				temp = temp->next;
				count++;
			}
			if (index == 0) {
				push_front(item);
			}
			else if (index == size) {
				push_back(item);
			}
			else {
				Node* new_node = new Node(item, temp, temp->prev);
				temp->prev->next = new_node;
				temp->prev = new_node;
				size++;
			}
		}
	}

//Remove function
	ItemType remove(int index) {

		return ItemType();

	}
//Find Function
	int find(const ItemType& item) {

		return -1;

	}
//Output function
	void print() {
		int count = 0;
		Node* temp = head;

		//while (temp != NULL) {
		cout << "print" << endl;
		while(count < size){
			cout << "node" << " " << count << ": " << temp->item << endl;
			temp = temp->next;
			count++;
		}
		

	}


};
