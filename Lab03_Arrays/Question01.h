#pragma once
#include<iostream>
using namespace std;

bool checkDuplicate(int res[], int size, int val) {
	for (int i = 0; i < size; i++) {
		if (val == res[i]) {
			return 1;
		}
	}
	return 0;
}

void findIntersection(int* arr1, int size1, int* arr2, int size2) {

	//finding max size to pass it to the dynamic array - WORST CASE
	int minSize = (size1 <= size2) ? size1 : size2;
	int* result= new int[minSize];
	//checkimg for same elements
	int count = 0;
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			if (arr1[i] == arr2[j]) {
				if (!checkDuplicate(result, count, arr1[i])) {
					result[count] = arr1[i];
						count++;
				}
			}
		}
	}

	if (count > 0) {
		cout << "Intersection is: ";
		for (int i = 0; i < count; i++) {
			cout << result[i] << " ";
		}
		delete[] result;
	}

	else {
		cout << "No intersection" << endl;
	}

}
