#pragma once
#include<iostream>

class DoublyNode {
	int data;
	DoublyNode* prev;
	DoublyNode* next;

public:
	DoublyNode() {
		prev = nullptr;
		next = nullptr;
	}

	DoublyNode(int d, DoublyNode* p, DoublyNode* n) {
		data = d;
		prev = p;
		next = n;
	}

	int getData() const {
		return data;
	}

	DoublyNode* getPrevious() const {
		return prev;
	}

	DoublyNode* getNext() const {
		return next;
	}

	void setData(int v) {
		data = v;
	}

	void setPrevious(DoublyNode* p) {
		prev = p;
	}

	void setNext(DoublyNode* n) {
		next = n;
	}
};

class DoublyLinkedList {
	DoublyNode* head;
public:
	DoublyLinkedList() {
		head = nullptr;
	}

	DoublyNode* getHead() const {
		return head;
	}

	bool isEmpty() {
		return(head == nullptr);
	}

	void insert(int val) {
		DoublyNode* newNode = new DoublyNode(val, nullptr, nullptr);
		if (isEmpty()) {
			head = newNode;
		}

		else {
			DoublyNode* temp = head;
			while (temp->getNext() != nullptr) {
				temp = temp->getNext();
			}

			temp->setNext(newNode);
			newNode->setPrevious(temp);
		}
	}

	void insertToHead(int val) {
		DoublyNode* newNode = new DoublyNode(val, nullptr, nullptr);
		if (isEmpty()) {
			head = newNode;
		}

		else {
			newNode->setNext(head);
			head = newNode;
		}
	}

	/*
	In linked lists, there is generally no need to implement an isFull
	function because linked lists don't have a fixed or predefined
	maximum size like arrays do. Linked lists are dynamic data structures
	that can grow or shrink as needed, depending on the available memory and the
	number of elements you insert or remove.
	*/

	bool search(int val) {
		DoublyNode* temp = head;
		while (temp != nullptr) {
			if (temp->getData() == val) {
				return true;
			}
			temp = temp->getNext();
		}
		return false;
	}

	void update(int val1, int val2) {
		DoublyNode* temp = head;
		while (temp != nullptr) {
			if (temp->getData() == val1) {
				temp->setData(val2);
					break;
			}
			temp = temp->getNext();
		}
	}

	void insertAtIndex(int val, int index) {
		DoublyNode* newNode = new DoublyNode(val, nullptr, nullptr);
		DoublyNode* temp = head;
		int count = 0;
		DoublyNode* previous;
		previous = nullptr;

		if (index == 0) {
			insertToHead(val);
			return;
		}

		while (temp != nullptr && count < index) {
			previous = temp;
			temp = temp->getNext();
			count++;
		}

		if (temp == nullptr && count < index) {
			return;
		}

		if (temp == nullptr && count == index) {
			insert(val);
		}

		temp->setPrevious(newNode);
		newNode->setNext(temp);
		previous->setNext(newNode);
	}

	void deleteData(int val) {
		DoublyNode* temp = head;
		DoublyNode* toBeRemoved = nullptr;

		while (temp != nullptr) {
			if (temp->getData() == val) {
				toBeRemoved = temp;
				break;
			}
			temp = temp->getNext();
		}

		if (toBeRemoved != nullptr) {
			DoublyNode* previous = toBeRemoved->getPrevious();
			DoublyNode* nextNode = toBeRemoved->getNext();
			previous->setNext(nextNode);
			nextNode->setPrevious(previous);

			delete toBeRemoved;
			toBeRemoved = nullptr;
		}
		return;
	}

	void print() {
		DoublyNode* temp = head;
		while (temp != nullptr) {
			std::cout << temp->getData() << " ";
			temp = temp->getNext();
		}
	}
};

// ------------------------------------------------------------- Question : 02 ------------------------------------------------------------- //

#pragma once


class Node {
	int data;
	Node* next;
public:
	Node() {
		next = nullptr;
	}

	Node(int val, Node* n) {
		data = val;
		next = n;
	}

	int getData() {
		return data;
	}

	Node* getNext() {
		return next;
	}

	void setData(int v) {
		data = v;
	}

	void setNext(Node* ptr) {
		next = ptr;
	}
};

class CircularLinkedList {
	Node* head;
public:
	CircularLinkedList() {
		head = nullptr;
	}

	Node* getHead() {
		return head;
	}

	bool isEmpty() {
		return(head == nullptr);
	}

	/*
	In linked lists, there is generally no need to implement an isFull
	function because linked lists don't have a fixed or predefined
	maximum size like arrays do. Linked lists are dynamic data structures
	that can grow or shrink as needed, depending on the available memory and the
	number of elements you insert or remove.
	*/

	void insert(int val) {
		Node* newNode = new Node(val, nullptr);
		if (isEmpty()) {
			head = newNode;
			newNode->setNext(head);
			return;
		}

		Node* temp = head;
		while (temp->getNext() != head) {
			temp = temp->getNext();
		}

		temp->setNext(newNode);
		newNode->setNext(head);
	}

	bool search(int val) {
		Node* temp = head;
		while (temp->getNext() != head) {
			if (temp->getData() == val) {
				return true;
			}
			temp = temp->getNext();
		}

		return false;
	}


	void print() {
		Node* temp = head;
		while (temp->getNext() != head) {
			std::cout << temp->getData() << " ";
			temp = temp->getNext();
		}
		std::cout << temp->getData() << " ";
		std::cout << std::endl;
	}

	void update(int val1, int val2) {
		Node* temp = head;
		while (temp->getNext() != head) {
			if (temp->getData() == val1) {
				temp->setData(val2);
				break;
			}
			temp = temp->getNext();
		}
	}

	void insertAtIndex(int val, int index) {
		Node* newNode = new Node(val, nullptr);
		Node* temp = head;

		if (index == 0) {
			newNode->setNext(head);
			head = newNode;
			return;
		}

		Node* previous;
		int count = 0;

		while (temp->getNext() != head && count < index) {
			previous = temp;
			temp = temp->getNext();
			count++;
		}

		if (temp == head && count == index) {
			insert(val);
			return;
		}

		if (temp == head && count < index) {
			return;
		}

		previous->setNext(newNode);
		newNode->setNext(temp);
	}

	void deleteData(int val) {
		if (isEmpty()) {
			// Handle the case where the list is empty
			return;
		}

		Node* toBeRemoved = nullptr;

		// Special handling for the head node
		if (head->getData() == val) {
			Node* tail = head;
			while (tail->getNext() != head) {
				tail = tail->getNext();
			}

			toBeRemoved = head;
			head = head->getNext();
			tail->setNext(head); // Update the tail's next to point to the new head

			delete toBeRemoved;
			return;
		}

		Node* current = head->getNext();
		Node* previous = head;

		while (current != head) {
			if (current->getData() == val) {
				toBeRemoved = current;
				previous->setNext(current->getNext());

				delete toBeRemoved;
				return;
			}

			previous = current;
			current = current->getNext();
		}
	}


	int findWinner(int el) {
		int count = 0;
		int del = 0;

		Node* temp = head;
		Node* tail = head;

		while (temp->getNext() != head) {
			temp = temp->getNext();
		}

		tail = temp;
		temp = head;
		Node* shortestNode = temp;
		int shortest = temp->getData();

		while (temp->getNext() != head) {
			temp = temp->getNext();
			count++;
		}
	
		temp = head;

		while (del != count) {
			shortestNode = temp;
			shortest = temp->getData();
			Node* current = temp;
			for (int i = 0; i < el - 1; i++) {
				temp = temp->getNext();

				if (temp->getData() == -1) {
					current = current->getNext();
					temp = temp->getNext();
				}

				if (shortest > temp->getData()) {
					shortestNode = temp;
					shortest = temp->getData();
				}
			}

			shortestNode->setData(-1);
			del++;

			if (del == 3) {
				el--;
			}

			temp = current;
			temp = temp->getNext();
		}

		head = temp;

		return head->getData();
	}
};



