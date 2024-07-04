#include<iostream>
#include<queue>
using namespace std;


// --------------------------------------------- Question 01 --------------------------------------------//

template<typename T>
class AVLNode {
public:
	T data;
	AVLNode* left;
	AVLNode* right;
	int height;

	AVLNode(T val) {
		data = val;
		left = nullptr;
		right = nullptr;
		height = 1;
	}
};

template <typename T>
class AVLTree {

	AVLNode<T>* root;

	//right rotation
	AVLNode<T>* rightRotate(AVLNode<T>* n) {
		AVLNode<T>* leftChild = n->left;
		AVLNode<T>* grandChild = leftChild->right;
		leftChild->right = n;
		n->left = grandChild;
		return leftChild;
	}

	//left rotation
	AVLNode<T>* leftRotate(AVLNode<T>* n) {
		AVLNode<T>* rightChild = n->right;
		AVLNode<T>* grandChild = rightChild->left;
		rightChild->left = n;
		n->right = grandChild;
		return rightChild;
	}

	// is max
	bool isMax(int num1, int num2) {
		return(num1 > num2);
	}

	//fix after insertion
	void fixAVLTree(AVLNode<T>*& n) {
		bool flag = false;
		queue<AVLNode<T>*> q1;
		q1.push(n);

		while (!q1.empty()) {
			AVLNode<T>* current = q1.front();
			q1.pop();

			if (balanceFactor(current) > 1 || balanceFactor(current) < -1) {
				AVLNode<T>* child = isMax(height(current->left), height(current->right)) ? current->left : current->right;
				if (child == current->left) {
					if (child->left != nullptr) {
						current = rightRotate(current);
					}
					else {
						current = leftRotate(current);
						current = rightRotate(current);
					}
				}

				else if (child == current->right) {
					if (child->right != nullptr) {
						current = leftRotate(current);
					}
					else {
						current = rightRotate(current);
						current = leftRotate(current);
					}
				}

				n = current;  
				break;
			}

			if (current->left != nullptr) {
				q1.push(current->left);
			}

			if (current->right != nullptr) {
				q1.push(current->right);
			}
		}
	}

	//inorder traversal
	void inOrderTraversal(AVLNode<T>* n) {
		if (n == nullptr) {
			return;
		}

		inOrderTraversal(n->left);
		cout << n->data << " ";
		inOrderTraversal(n->right);
	}

	//find smallest
	AVLNode<T>* findSmallest(AVLNode<T>* node) {
		if (node == nullptr || node->left == nullptr) {
			return node;
		}

		return findSmallest(node->left);
	}

	//find largest
	AVLNode<T>* findLargest(AVLNode<T>* node) {
		if (node == nullptr || node->right == nullptr) {
			return node;
		}

		return findLargest(node->right);
	}

	//diameter
	int diameter(AVLNode<T>* root) {

		int lheight = height(root->left);
		int rheight = height(root->right);

		return lheight + rheight;
	}

public:

	//Constructor
	AVLTree() {
		root = nullptr;
	}

	//getter
	AVLNode<T>* getRoot() {
		return root;
	}

	//Insertion
	void insert(T val) {
		AVLNode<T>* newNode = new AVLNode<T>(val);

		if (root == nullptr) {
			root = newNode;
		}

		else {
			AVLNode<T>* current = root;
			while (current) {
				if (val < current->data) {
					if (current->left == nullptr) {
						current->left = newNode;
						break;
					}
					else {
						current = current->left;
					}
				}

				else if (val > current->data) {
					if (current->right == nullptr) {
						current->right = newNode;
						break;
					}
					else {
						current = current->right;
					}
				}

				else {
					cout << "Item already exists." << endl;
					delete newNode;
					return;
				}
			}
		}

		fixAVLTree(root);

	}

	//max
	int max(int num1, int num2) {
		if (num1 > num2) {
			return num1;
		}

		return num2;
	}

	//Calculate Height
	int height(AVLNode<T>* n) {
		if (n == nullptr) {
			return 0;
		}

		int leftheight = height(n->left);
		int rightheight = height(n->right);

		n->height = max(leftheight, rightheight) + 1;
		return n->height;
	}

	//Calculate Balance Factor
	int balanceFactor(AVLNode<T>* n) {
		return (height(n->left) - height(n->right));
	}

	//Check if Avl treee or not
	bool isAVLTree(AVLNode<T>* n) {
		if (n == nullptr) {
			return true;
		}

		if (balanceFactor(n) > 1 || balanceFactor(n) < -1) {
			return false;
		}

		isAVLTree(n->left);
		isAVLTree(n->right);
	}

	//display
	void display() {
		cout << "In-order traversal: ";
		inOrderTraversal(root);
		cout << endl;
	}

	//deletion
	void remove(T val) {

		AVLNode<T>* trailCurrent = nullptr;
		AVLNode<T>* current = root;

		// Search for the node to remove.
		while (current != nullptr && current->data != val)
		{
			trailCurrent = current;

			if (val < current->data) {
				current = current->left;
			}

			else {
				current = current->right;
			}
		}

		if (current == nullptr) {
			return;
		}

		if (current->left == nullptr && current->right == nullptr)
		{
			if (trailCurrent == nullptr) {
				root = nullptr;
			}

			else if (trailCurrent->left == current) {
				trailCurrent->left = nullptr;
			}

			else {
				trailCurrent->right = nullptr;
			}

			delete current;
		}


		//  Node has one child.
		else if (current->left == nullptr || current->right == nullptr)
		{
			AVLNode<T>* child = (current->left != nullptr) ? current->left : current->right;

			if (trailCurrent == nullptr) {
				root = child;
			}

			else if (trailCurrent->left == current) {
				trailCurrent->left = child;
			}

			else {
				trailCurrent->right = child;
			}

			delete current;
		}

		else {
			AVLNode<T>* successor = current->right;
			AVLNode<T>* successorParent = current;
			while (successor->left != nullptr)
			{
				successorParent = successor;
				successor = successor->left;
			}

			if (trailCurrent == nullptr) {
				root = successor;
			}

			else if (trailCurrent->left == current) {
				trailCurrent->left = successor;
			}

			else {
				trailCurrent->right = successor;
			}

			if (successorParent->left == successor) {
				successorParent->left = successor->right;
			}

			else {
				successorParent->right = successor->right;
			}

			successor->left = current->left;
			successor->right = current->right;
			delete current;
		}

		fixAVLTree(root);
	}

	//find smallest
	AVLNode<T>* findSmallest() {
		return findSmallest(root);
	}

	//find largest
	AVLNode<T>* findLargest() {
		return findLargest(root);
	}

	// ----------------------------------------------------- Question : 02 ----------------------------------------------------------- //

	int getDiameter() {
		return diameter(root);
	}
};



