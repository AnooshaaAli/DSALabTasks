#pragma once
#include<iostream>
using namespace std;

// ----------------------------------- Question 01 ----------------------------------------- //
const int cap = 7;

class Node {
public:
	int key;
	int value;
	Node* next;

	Node() {
		key = -1;
		value = -1;
		next = nullptr;
	}

	Node(int k, int v) {
		key = k;
		value = v;
		next = nullptr;
	}
};

class HashMap {
	int num_of_elements;
	int capacity;
	Node** arr_of_linkedlist;

public:
	HashMap() {
		num_of_elements = 0;
		capacity = cap;
		arr_of_linkedlist = new Node * [capacity];
		for (int i = 0; i < capacity; i++) {
			arr_of_linkedlist[i] = nullptr;
		}
	}

	int hashFunction(int key) {
		return (key % capacity);
	}

	void insert(int k, int v) {
		Node* newNode = new Node(k, v);
		int hIndex = hashFunction(k);

		if (arr_of_linkedlist[hIndex] == nullptr) {
			arr_of_linkedlist[hIndex] = newNode;
		}

		else {
			newNode->next = arr_of_linkedlist[hIndex];
			arr_of_linkedlist[hIndex] = newNode;
		}
		num_of_elements++;
	}

	int search(int key) {
		int hIndex = hashFunction(key);
		Node* temp = arr_of_linkedlist[hIndex];
		while (temp != nullptr) {
			if (temp->key == key) {
				return temp->value;
			}
			temp = temp->next;
		}
		return -1;
	}

	void remove(int key) {
		int hIndex = hashFunction(key);
		Node* temp = arr_of_linkedlist[hIndex];
		Node* prev = nullptr;

		while (temp != nullptr) {
			if (temp->key == key) {
				if (prev) {
					prev->next = temp->next;
				}

				else {
					arr_of_linkedlist[hIndex] = temp->next;
				}

				delete temp;
				temp = nullptr;
				num_of_elements--;
				return;
			}

			prev = temp;
			temp = temp->next;
		}
	}

	int findLargestElement() {
		int curr = 0;
		int count = 1;
		Node* temp = arr_of_linkedlist[0];

		while (temp == nullptr && curr < capacity - 1) {
			curr++;
			temp = arr_of_linkedlist[curr];
		}

		if (temp == nullptr) {
			return -1;
		}

		int largest = arr_of_linkedlist[curr]->value;

		while (count != num_of_elements && curr != capacity - 1) {
			while (temp == nullptr) {
				curr++;
				temp = arr_of_linkedlist[curr];
			}

			if (temp->value > largest) {
				largest = temp->value;
			}

			temp = temp->next;
			count++;
		}

		return largest;
	}

	int findMajorityElement() {
		int count = 0;
		int largest = findLargestElement();

		if (largest == -1) {
			return -1;
		}

		largest++;
		int* val = new int[largest];
		for (int i = 0; i < largest; i++) {
			val[i] = 0;
		}

		int num = 0;
		Node* temp = arr_of_linkedlist[0];
		while (count != num_of_elements && num != capacity - 1) {
			if (temp == nullptr) {
				num++;
				temp = arr_of_linkedlist[num];
				continue;
			}

			count++;
			val[temp->value]++;
			temp = temp->next;
		}

		int majIndex = val[0];
		int majVal = 0;
		for (int i = 1; i < largest; i++) {
			if (majIndex < val[i]) {
				majVal = i;
				majIndex = val[i];
			}
		}

		return majVal;
	}
};

