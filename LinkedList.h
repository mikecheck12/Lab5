#pragma once
#include <iostream>

template <typename ItemType>

struct LinkedList {


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
	Node* temp;
	int size = 0;
	int count;



//Clear function
	void clear(){
			while (head != NULL) {
				Node* current = head;
				head = head->next;
				delete current;
			}
			tail = NULL;
			size = 0;
	}

//insert items to front of list
	void push_front(const ItemType& item) {
		if (size == 0) {
			head = new Node(item, NULL, NULL);
		}
		else {
			//head = new Node(item, NULL, head);
			head = new Node(item, head, NULL);

			if (head->next != NULL) {
				head->next->prev = head;
			}
			if (tail == NULL) {
				tail = head;
				size++;
			}
		}
	}
//insert items on back of list
	void push_back(const ItemType& item) {
		if (tail != NULL) {
			tail->next = new Node(item, tail, NULL);
			tail = tail->next;
			size++;
		}
		else {
			push_front(item);
		}
	}

//insert items inside the list
	void insert(int index, const ItemType& item) {
		count = 0;
		temp = head;
		while (count != index) {
			temp = temp->next;
			count++;
		}
		if (index == 0) {
			push_front(item);
			size++;
		}
		else if (index >= size) {
			push_back(item);
			size++;
		}
		else {
			Node* new_node = new Node(item, temp, temp->prev);
			temp->prev->next = new_node;
			temp->prev = new_node;
			size++;
		}
	}

	ItemType remove(int index) {

		return ItemType();

	}

	int find(const ItemType& item) {

		return -1;

	}

	void print() {
		count = 0;
		temp = head;

		//while (temp != NULL) {
		while(count < 2){
			cout << "node" << " " << count << ": " << temp->item << endl;
			cout << size << endl;
			temp = temp->next;
			count++;
		}
	}


};
