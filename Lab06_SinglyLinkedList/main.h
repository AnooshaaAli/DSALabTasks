#pragma once
#include<iostream>
using namespace std;

template <typename T>
class Node {
public:
	T data;
	Node* next;

	Node() {

	}

	Node(T val) {
		data = val;
	}

	void setData(T v) {
		data = v;
	}

	void setNext(Node* ptr) {
		next = ptr;
	}

	T getData() const {
		return data;
	}

	Node* getNext() const {
		return next;
	}
};

template <typename T>
class SLinkedList {
public:
	Node<T>* head;

	SLinkedList() {
		head = nullptr;
	}

	void insert(T number) {
		Node<T>* instance = new Node<T>(number);
		instance->next = nullptr;

		if (head == nullptr) {
			head = instance;
			return;
		}

		Node<T>* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}

		temp->next = instance;
	}

	void insertAtHead(T number) {
		Node<T>* instance = new Node<T>(number);
		instance->next = head;
		head = instance;
	}

	bool isEmpty() {
		if (head == nullptr) {
			return true;
		}

		return false;
	}

	/*
	In linked lists, there is generally no need to implement an isFull
	function because linked lists don't have a fixed or predefined
	maximum size like arrays do. Linked lists are dynamic data structures
	that can grow or shrink as needed, depending on the available memory and the
	number of elements you insert or remove.
	*/

	void InsertAtIndex(T val, int index) {

		if (index == 0) {
			insertAtHead(val);
			return;
		}

		Node<T>* newInstance = new Node<T>(val);
		Node<T>* prev = head;
		Node<T>* current = head->next;
		int count = 0;

		while (current != nullptr && count < index) {
			current = current->next;
			prev = prev->next;
		}

		prev->next = newInstance;
		newInstance->next = current;
		if (count == index) {
			current->next = newInstance;
			newInstance->next = nullptr;
		}
		return;
	}

	int search(T val) {
		if (!isEmpty()) {
			Node<T>* temp = head;
			while (temp != nullptr) {
				if (temp->data == val) {
					return temp->data;
				}
				temp = temp->next;
			}
		}
		return -1;
	}

	void update(int index, T val) {
		Node<T>* random = head;
		int count = 0;

		while (random->next != nullptr && count < index) {
			random = random->next;
			count++;
		}

		random->data = val;
	}

	void remove(T val) {
		if (!isEmpty()) {
			Node<T>* prev = head;
			Node<T>* toBeRemoved = head->next;

			while (toBeRemoved != nullptr) {
				if (toBeRemoved->data == val) {
					prev->next = toBeRemoved->next;
					delete toBeRemoved;
					toBeRemoved = nullptr;
					break;
				}

				toBeRemoved = toBeRemoved->next;
				prev = prev->next;
			}
		}

		return;
	}

	void print() {
		Node<T>* temp = head;
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};

template <typename T>
Node<T>* swapAdjacentNodes(Node<T>* start) {
	if (start == nullptr || start->next == nullptr) {
		return start;
	}

	Node<T>* current = start;
	Node<T>* prev = nullptr;
	Node<T>* second = start->next;
	Node<T>* newHead = start->next;

	while (current != nullptr && second != nullptr) {

		second = current->next;
		current->next = second->next;
		second->next = current;

		if (prev != nullptr) {
			prev->next = second;
		}

		prev = current;
		current = current->next;
	}


	return newHead;
}
