#include<iostream>
#include <stack>
#include<algorithm>
using namespace std;

template <typename T>
class binaryTreeNode {
public:
	T data;
	binaryTreeNode<T>* llink;
	binaryTreeNode<T>* rlink;

	binaryTreeNode(T val = T()) {
		data = val;
		llink = nullptr;
		rlink = nullptr;
	}
};

template <typename T>
class BST {
public:
	binaryTreeNode<T>* root;
	BST() {
		root = nullptr;
	}

	void insert(T item) {
		binaryTreeNode<T>* newNode = new binaryTreeNode<T>(item);

		if (root == nullptr) {
			root = newNode;
		}

		else {
			binaryTreeNode<T>* current = root;
			while (current) {
				if (item < current->data) {
					if (current->llink == nullptr) {
						current->llink = newNode;
						break;
					}
					else {
						current = current->llink;
					}
				}

				else if (item > current->data) {
					if (current->rlink == nullptr) {
						current->rlink = newNode;
						break;
					}
					else {
						current = current->rlink;
					}
				}

				else {
					cout << "Item already exists." << endl;
					delete newNode;
					return;
				}
			}
		}
	}

	bool search(T searchItem) {

		binaryTreeNode<T>* current = root;

		while (current != nullptr) {
			if (current->data == searchItem) {
				return true;
			}

			else if (searchItem < current->data) {
				current = current->llink;
			}

			else {
				current = current->rlink;
			}
		}

		return false;
	}

	void inOrderTraversal(binaryTreeNode<T>* n) {

		if (n == nullptr) {
			return;
		}

		inOrderTraversal(n->llink);
		cout << n->data << " ";
		inOrderTraversal(n->rlink);
	}

	void inOrderTraversal() {
		inOrderTraversal(root);
		cout << endl;
	}

	void preOrderTraversal(binaryTreeNode<T>* n) {

		if (n == nullptr) {
			return;
		}

		cout << n->data << " ";
		preOrderTraversal(n->llink);
		preOrderTraversal(n->rlink);
	}

	void preOrderTraversal() {
		preOrderTraversal(root);
		cout << endl;
	}

	void postOrderTraversal(binaryTreeNode<T>* n) {

		if (n == nullptr) {
			return;
		}

		postOrderTraversal(n->llink);
		postOrderTraversal(n->rlink);
		cout << n->data << " ";
	}

	void postOrderTraversal() {
		postOrderTraversal(root);
		cout << endl;
	}

	void remove(T searchItem)
	{

		binaryTreeNode<T>* trailCurrent = nullptr;
		binaryTreeNode<T>* current = root;

		while (current != nullptr && current->data != searchItem)
		{
			trailCurrent = current;

			if (searchItem < current->data) {
				current = current->llink;
			}

			else {
				current = current->rlink;
			}
		}

		if (current == nullptr) {
			return;
		}

		//Leaf Node
		if (current->llink == nullptr && current->rlink == nullptr)
		{
			if (trailCurrent == nullptr) {
				root = nullptr;
			}

			else if (trailCurrent->llink == current) {
				trailCurrent->llink = nullptr;
			}

			else {
				trailCurrent->rlink = nullptr;
			}

			delete current;
		}


		// One child 
		else if (current->llink == nullptr || current->rlink == nullptr)
		{
			binaryTreeNode<T>* child = (current->llink != nullptr) ? current->llink : current->rlink;

			if (trailCurrent == nullptr) {
				root = child;
			}

			else if (trailCurrent->llink == current) {
				trailCurrent->llink = child;
			}

			else {
				trailCurrent->rlink = child;
			}

			delete current;
		}

		// two child
		else {
			binaryTreeNode<T>* successor = current->rlink;
			binaryTreeNode<T>* successorParent = current;

			while (successor->llink != nullptr)
			{
				successorParent = successor;
				successor = successor->llink;
			}

			if (trailCurrent == nullptr) {
				root = successor;
			}

			else if (trailCurrent->llink == current) {
				trailCurrent->llink = successor;
			}

			else {
				trailCurrent->rlink = successor;
			}

			if (successorParent->llink == successor) {
				successorParent->llink = successor->rlink;
			}

			else {
				successorParent->rlink = successor->rlink;
			}

			successor->llink = current->llink;
			successor->rlink = current->rlink;
			delete current;
		}
	}

	// ---------------------------------------- Question : 02 --------------------------------------//

	int countLeafNodes(binaryTreeNode<T>* root) {
		if (root == nullptr) {
			return 0;
		}

		if (root->rlink == nullptr && root->llink == nullptr) {
			return 1;
		}

		return countLeafNodes(root->llink) + countLeafNodes(root->rlink);
	}

	int countleaf() {
		return countLeafNodes(root);
	}

	// ----------------------------------------------------------------------------------------------------------------------------------------------- //
	//search index
	int search(char arr[], int strt, int end, char value)
	{
		int i;
		for (i = strt; i <= end; i++)
		{
			if (arr[i] == value)
				return i;
		}
	}

	//construct a binary tree using inorder and preorder
	binaryTreeNode<T>* buildTreeUsingPreOrder(char in[], char pre[], int s, int e) {
		static int preIndex = 0;

		if (s > e) {
			return nullptr;
		}

		// Find the index of the current element in the inorder traversal
		int inIndex = search(in, s, e, pre[preIndex]);

		// Create a new node for the current preorder element
		binaryTreeNode<char>* newNode = new binaryTreeNode<char>(pre[preIndex]);
		preIndex++;

		// If the tree is empty, set the root
		if (root == nullptr) {
			root = newNode;
		}

		// Build the left and right subtrees
		newNode->llink = buildTreeUsingPreOrder(in, pre, s, inIndex - 1);
		newNode->rlink = buildTreeUsingPreOrder(in, pre, inIndex + 1, e);

		return newNode;
	}

	binaryTreeNode<T>* buildTreeUsingPostOrder(char in[], char post[], int s, int e) {
		static int postIndex = e - 1;

		if (s > e) {
			return  nullptr;
		}

		// Create a new node for the current preorder element
		binaryTreeNode<char>* newNode = new binaryTreeNode<char>(post[postIndex]);
		postIndex--;

		// If the tree is empty, set the root
		if (root == nullptr) {
			root = newNode;
		}

		int inIndex = searchsearch(in, s, e, newNode->data);

		newNode->llink = buildTreeUsingPostOrder(in, post, s, inIndex - 1);
		newNode->rlink = buildTreeUsingPostOrder(in, post, inIndex + 1, e);

		return newNode;
	}

	int height(binaryTreeNode<T>* N) {
		if (n == nullptr) {
			return 0;
		}

		return 1 + max(height(n->llink) + height(rlink));
	}

	bool isBalanced(binaryTreeNode<T>* node) {
		if (node == nullptr) {
			return true;
		}

		if (height(node->llink) - height(node->rlink) <= 1 || height(node->llink) - height(node->rlink) >= -1) {
			if(isBalanced(node->llink) && isBalanced(node->rlink))
				return true;
		}

		return false;
	}

	//binaryNodeTree<T>* firstUnbalancedNodeFromGround() {

	//}

	//binaryNodeTree<T>* firstUnbalancedNodeFromGround() {

	//}
};



