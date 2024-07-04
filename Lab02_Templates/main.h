//
// pch.h
//

#pragma once

#include "gtest/gtest.h"
#include<iostream>
using namespace std;

template <typename T, int size>
T DotProduct(T arr1[], T arr2[]) {
	T prod = 0;
	for (int i = 0; i < size; i++) {
		prod += arr1[i] * arr2[i];
	}
	return prod;
}

template <typename T>
T findNthModifiedFibonacci(int num) {

	T res = 0;
	T fib0 = 0;
	T fib1 = 1;
	T fib2 = 1;

	if (num == 0) {
		return 0;
	}

	else if (num == 1) {
		return 1;
	}

	else if (num == 2) {
		return 1;
	}

	else {
		for (int i = 3; i <= num; i++) {
			res = fib0 + fib1 + fib2;
			fib0 = fib1;
			fib1 = fib2;
			fib2 = res;
		}
		return res;
	}
}

// Function for spiralOrderTraversal
template <typename T, size_t rows, size_t cols>
void spiralOrderTraversal(T(&array)[rows][cols], T res[]) {
	int  top = 0, bottom = rows - 1, left = 0, right = cols - 1;
	int count = 0;

	while (top <= bottom && left <= right) {

		for (int i = left; i <= right; ++i) {
			res[count++] = array[top][i];
		}
		++top;

		for (int i = top; i <= bottom; ++i) {
			res[count++] = array[i][right];
		}
		--right;

		if (top <= bottom && left <= right) {

			for (int i = right; i >= left; --i) {
				res[count++] = array[bottom][i];
			}
			--bottom;

			for (int i = bottom; i >= top; --i) {
				res[count++] = array[i][left];
			}
			++left;
		}
	}
}


template <class T>
class OnlineBank {
	T currentBalance;
	T* withdrawals;
	T* deposits;
	int numOfTransactions;
	int counterWithdrawal;
	int counterDeposits;
public:
	OnlineBank(T B, int num) {
		currentBalance = B;
		numOfTransactions = num;
	}

	bool isWithdrawal() {
		return (counterWithdrawal < numOfTransactions);
	}

	bool isDeposit() {
		return (counterDeposits < numOfTransactions);
	}

	bool makeWithdrawal(T val) {
		if (val <= currentBalance && counterWithdrawal < numOfTransactions) {
			currentBalance -= val;
			return true;
		}
		return false;
	}

	void makeDeposit(T val) {
		if (counterDeposits < numOfTransactions) {
			currentBalance += val;
		}
	}

	T& getCurrentBalance() {
		return currentBalance;
	}

	void print() {
		cout << "CurrentBalance= " << currentBalance << endl;
	}

};
