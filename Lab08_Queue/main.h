#include <iostream>
#include "time.h"
#include <cstdlib>
#include <string>
using namespace std;

template <typename T>
class Node {
public:
	T data;
	Node* next;
};

template <typename T>
class Queue {
public:
	Node<T>* front;
	Node<T>* rear;

	Queue() {
		front = nullptr;
		rear = nullptr;
	}

	bool is_empty() {
		return(front == nullptr);
	}

	T Front() {
		if (is_empty()) {
			return T();
		}

		return front->data;
	}

	void enqueue(T val) {
		Node<T>* newNode = new Node<T>();
		newNode->data = val;
		newNode->next = nullptr;

		if (front == nullptr) {
			front = newNode;
			rear = newNode;
			return;
		}

		rear->next = newNode;
		rear = newNode;
	}

	T dequeue() {
		T val;
		if (is_empty()) {
			return T();
		}

		Node<T>* temp = front;
		val = front->data;
		front = front->next;
		delete temp;
		temp = nullptr;
		return val;
	}

	T peek() {
		if (is_empty()) {
			return -1;
		}

		return front->data;
	}

	int size() {
		Node<T>* temp = front;
		int count = 0;
		while (temp != nullptr) {
			count++;
			temp = temp->next;
		}

		return count;
	}

	void clear() {

		while (front != nullptr) {
			Node<T>* temp = front;
			front = front->next;
			delete temp;
			temp = nullptr;
		}
	}

	void print(Queue& Q) {
		Node<T>* temp = Q.front;
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	bool isPalindrome(const string& str) {
		Queue<T> Q;
		int i = 0;

		while (str[i]) {
			Q.enqueue(str[i]);
			i++;
		}

		Q.print(Q);
		i--;

		while (i >= 0) {
			int ch = Q.dequeue();

			if (ch != str[i]) {
				return false;
			}

			i--;
		}

		return true;
	}
};

// ------------------------------------------------------ Question : 02 -----------------------------------------------------------//

class Process {
public:
	int processID;
	int state;
	int executionTime;
	bool onceBlocked;

	//constructors
	Process() {
		processID = 0;
		state = 0;
		executionTime = 0;
		onceBlocked = false;
	}

	Process(int id, int time) {
		processID = id;
		state = 0;
		executionTime = time;
		onceBlocked = false;
	}
};


void simulateProcessScheduling(Queue<Process>& n, Queue<Process>& r, Queue<Process>& rn, Queue<Process>& b, Queue<Process>& t, int num) {
	srand(static_cast<unsigned>(time(0)));
	int Id = 1;

	for (int i = 0; i < num; i++) {
		int random = 1 + rand() % 5;

		Process P(Id, random);
		n.enqueue(P);
		Id++;
	}

	while(true){
	if (!n.is_empty() || !r.is_empty() || !rn.is_empty() || !b.is_empty()) {
		//int random = 1 + rand() % 5;

		//Process P(Id, random);
		//n.enqueue(P);
		//Id++;
		break;
	}
		while (!n.is_empty()) {
			Process P2 = n.dequeue();
			P2.state = 1;
			r.enqueue(P2);
		}

		if (rn.is_empty() && !r.is_empty()) {
			Process P3 = r.dequeue();
			P3.state = 2;
			P3.executionTime =- 2;
			rn.enqueue(P3);
		}

		if (!rn.is_empty()) {
			Process P5 = rn.dequeue();
			int random2 = rand();

			if (P5.executionTime == 0) {
				P5.state = 4;
				t.enqueue(P5);

			}

			else if (random2 % 10 == 0) {
				P5.state = 3;
				b.enqueue(P5);
				P5.onceBlocked = true;
				Process P6;
				P6 = rn.dequeue();
			}

			else {
				P5.state = 1;
				r.enqueue(P5);
			}

			int random3 = rand();
			if (!b.is_empty() && random3 % 100 == 0) {
				Process P7;
				P7 = b.dequeue();
				P7.state = 1;
				r.enqueue(P7);
			}
		}
		}
	}

















//	while (!newQueue.is_empty() || !readyQueue.is_empty() || !runningQueue.is_empty() || !blockedQueue.is_empty()) {
//		// Generate a random number between 1 and 5 to determine execution time
//		int executionTime = 1 + std::rand() % 5;
//
//		// Create a new process
//		Process newProcess(processIDCounter, executionTime);
//		newQueue.enqueue(newProcess);
//		processIDCounter++;
//
//		// Move processes from New to Ready
//		while (!newQueue.empty()) {
//			Process newProcess = newQueue.dequeue();
//			newProcess.state = 1;  // Ready
//			readyQueue.enqueue(newProcess);
//		}
//
//		// If the running queue is empty and there are processes in the ready queue, move one to Running
//		if (runningQueue.empty() && !readyQueue.empty()) {
//			Process runningProcess = readyQueue.dequeue();
//			runningProcess.state = 2;  // Running
//			runningQueue.enqueue(runningProcess);
//		}
//
//		// Execute the running process for a time quantum of 2 seconds
//		for (int i = 0; i < 2 && !runningQueue.empty(); i++) {
//			Process& runningProcess = runningQueue.Front();
//			runningProcess.executionTime--;
//
//			if (runningProcess.executionTime == 0) {
//				runningProcess.state = 4;  // Terminated
//				terminatedQueue.enqueue(runningProcess);
//				runningQueue.dequeue();
//			}
//			else if (runningProcess.executionTime % 10 == 0) {
//				runningProcess.state = 3;  // Blocked
//				blockedQueue.enqueue(runningProcess);
//				runningQueue.dequeue();
//				runningProcess.onceBlocked = true;
//			}
//		}
//
//		// Move processes from Blocked to Ready (if their execution time is divisible by 100)
//		while (!blockedQueue.empty()) {
//			Process blockedProcess = blockedQueue.dequeue();
//			if (blockedProcess.executionTime % 100 == 0) {
//				blockedProcess.state = 1;  // Ready
//				readyQueue.enqueue(blockedProcess);
//			}
//			else {
//				blockedQueue.enqueue(blockedProcess);
//			}
//		}
//
//		// Display the state of each process at each step
//		// You can add the code here to display the process states
//	}
//}
