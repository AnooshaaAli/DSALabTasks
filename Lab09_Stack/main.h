#pragma once

#include "gtest/gtest.h"
#include <stack>
#include<iostream>
#include <string>

using namespace std;

template <typename T>
class Node {
public:
	T data;
	Node* next;
};

template <typename T>
class Stack {
public:
	Node<T>* top;
	Stack() {
		top = nullptr;
	}

	bool isEmpty() {
		return(top == nullptr);
	}

	void push(const T item) {
		Node<T>* newNode = new Node<T>();
		newNode->data = item;
		newNode->next = nullptr;

		if (isEmpty()) {
			top = newNode;
			return;
		}

		newNode->next = top;
		top = newNode;
	}

	void pop() {
		if (isEmpty()) {
			throw std::runtime_error("Stack is Empty");
		}

		Node<T>* temp = top;
		top = top->next;
		delete temp;
	}

	T peek() {
		if (isEmpty()) {
			throw std::runtime_error("Stack is Empty");
		}

		return top->data;
	}

	void clear() {
		while (!isEmpty()) {
			pop();
		}
	}

	void print() {
		Node<T>* temp = top;
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	~Stack() {
		clear();
	}
};

//--------------------------------------------- Question : 03 ------------------------------------------------------//

string simplifyPath(string path) {
	Stack<char> stack;
	string result = "";
	stack.push(path[0]);

	if (stack.peek() != '/') {
		return result;
	}

	int i = 1;
	while (path[i]) {
		if (stack.peek() == '.') {
			stack.pop();
			i++;
			continue;
		}

		if (stack.peek() == '/' && path[i] == '/') {
			i++;
			continue;
		}

		stack.push(path[i]);
		i++;
	}

	if (stack.peek() == '/') {
		stack.pop();
		if (stack.isEmpty()) {
			stack.push('/');
		}
	}

	Stack<char> stack2;
	while (!stack.isEmpty()) {
		stack2.push(stack.peek());
		stack.pop();
	}

	while (!stack2.isEmpty()) {
		result += stack2.peek();
		stack2.pop();
	}

	return result;
}

//--------------------------------------------- Question : 02 ------------------------------------------------------//
string removeKDigits(string str, int k) {
	string result = "";
	Stack<char> stack;
	int i = 0;
	int pops = 0;
	int size = str.size();

	int count = size - k;

	while (str[i]) {
		while (pops < k && !stack.isEmpty() && str[i] < stack.peek()) {
			stack.pop();
			pops++;
		}

		stack.push(str[i]);
		i++;
	}

	int length = 0;
	Node<char>* temp = stack.top;
	while (temp) {
		length++;
		temp = temp->next;
	}


	while (length > count) {
		stack.pop();
		length--;
	}

	while (!stack.isEmpty()) {
		result = stack.peek() + result;
		stack.pop();
	}

	int numZeros = 0;
	int index = 0;
	while (result[index]) {
		if (result[index] == '0') {
			numZeros++;
		}
		else {
			break;
		}
		index++;
	}

	result = result.substr(numZeros);

	if (result == "") {
		result = "0";
	}

	return result;
}
