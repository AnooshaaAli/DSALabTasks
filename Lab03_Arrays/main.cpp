#include<iostream>
#include<string>
#include "Question01.h"
#include "Question02.h"
#include "Question03.h" 
#include "Question04.h" 
using namespace std;

int main() {

	                                                         //Question#01
	cout << "Question: 01" << endl << endl;
	int size1;
	int size2;
	cout << "Enter the size of array1: ";
	cin >> size1;
	int* array1 = new int[size1];

	cout << "Enter values for the array1: " << endl;
	for (int i = 0; i < size1; i++) {
		cin >> array1[i];
	}

	cout << "Enter the size of array2: ";
	cin >> size2;
	int* array2 = new int[size2];

	cout << "Enter values for the array2: " << endl;
	for (int i = 0; i < size2; i++) {
		cin >> array2[i];
	}

	findIntersection(array1, size1, array2, size2);
	cout << endl << endl;

	                                                          //Question#02
	cout << "Question: 02" << endl << endl;
	int nums[] = { 1,17,8 };
	int size = 3;
	int numPermutations = findUniquePermutations(nums, 3);
	cout << numPermutations << endl;

	                                                          //Question#03
	cout << "Question: 03" << endl << endl;
	int size01 = 1;
	int array[] = { 5 };
	float average = maxAverage(array, size01, 1);
	cout << average << endl;

	                                                          //Question#04
	cout << "Question: 04" << endl << endl;
	const int num_users = 4;
	string user_profiles[num_users] = { "UserA", "UserB", "UserC", "UserD" };
	string user_interests[num_users][3] = {
{"hiking", "photography", "cooking"},
{"photography", "travel", "painting"},
{"cooking", "gaming", "movies"},
{"hiking", "travel", "photography"}
	};
	string PotentialFriend = recommendFriend(user_profiles[0], user_profiles, user_interests, num_users);
	cout << PotentialFriend << endl;
	return 0;
}
