#pragma once
#include<iostream>
#include <queue>
#include <stack>
using namespace std;

// --------------------------------------------- Question : 01 -------------------------------------------------- //
//class BinaryTree {
//public:
//	int* treeArray;
//	int capacity;
//	int root;
//	int current_index;
//
//	BinaryTree(int num = 100) {
//		capacity = num;
//		treeArray = new int[capacity];
//
//		for (int i = 0; i < capacity; i++) {
//			treeArray[i] = -1;
//		}
//
//		root = 0;
//		current_index = 0;
//	}
//
//	void insert(int val) {
//		if (current_index < capacity) {
//			treeArray[current_index] = val;
//			current_index++;
//		}
//		else {
//			cout << "Tree is Full" << endl;
//			return;
//		}
//	}
//
//	void inorderTraversal(int index) {
//		if (treeArray[index] == -1) {
//			return;
//		}
//
//		inorderTraversal(2 * index + 1);
//		cout << treeArray[index] << " ";
//		inorderTraversal(2 * index + 2);
//	}
//
//	void displayInorder() {
//		inorderTraversal(root);
//	}
//};

// --------------------------------------------- Question : 02 -------------------------------------------------- //

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int d) {
		data = d;
		left = nullptr;
		right = nullptr;
	}
};

class BinaryTree {
public:
	Node* root;

	BinaryTree() {
		root = nullptr;
	}

	void insert(int val) {
		Node* newNode = new Node(val);

		if (root == nullptr) {
			root = newNode;
			return; // Return after setting the root
		}
		else {
			queue<Node*> Q;
			Q.push(root);

			while (!Q.empty()) {
				Node* currentNode = Q.front();
				Q.pop();

				if (currentNode->left != nullptr) {
					Q.push(currentNode->left);
				}
				else {
					currentNode->left = newNode;
					break;
				}

				if (currentNode->right != nullptr) {
					Q.push(currentNode->right);
				}
				else {
					currentNode->right = newNode;
					break;
				}
			}
		}
	}


	void inorderTraversal(Node* root) {
		if (root == nullptr) {
			return;
		}

		inorderTraversal(root ->left);
		cout << root->data << " ";
		inorderTraversal(root->right);
	}

	void display() {
		inorderTraversal(root);
		cout << endl;
	}
};

// --------------------------------------------- Question : 03 -------------------------------------------------- //
class TreeNode {
public:
	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		data = val;
		left = nullptr;
		right = nullptr;
	}
};

void dfs(TreeNode* n, stack<int>& S) {
	if (!n) {
		return;
	}
	dfs(n->left, S);
	S.push(n->data);
	dfs(n->right, S);
}

int kthSmallest(TreeNode* root, int k) {
	stack<int> S;
	dfs(root, S);

	for (int i = 0; i < k - 1; i++) {
		S.pop(); 
	}

	int kthSmallest = S.top();
	return kthSmallest;
}
