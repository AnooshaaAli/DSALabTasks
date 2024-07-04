#pragma once
#include<iostream>
#include<time.h>
using namespace std;

// -------------------------------------------------- Question 01 ---------------------------------------------- //
const int tableSize = 7;

class HashEntry {
public:
	int key;
	int value;
};

class HashMap {
public:
	HashEntry* HT;

	HashMap() {
		HT = new HashEntry[tableSize];
		for (int i = 0; i < tableSize; i++) {
			HT[i].key = -1;
		}
	}

	int hashFunction(int key) {
		return (key % tableSize);
	}

	void insert1(int key, int value) {

		int hIndex = hashFunction(key);

		bool found = false;
		while (HT[hIndex].key != -1 && !found) {
			if (HT[hIndex].key == key)
				found = true;
			else
				hIndex = (hIndex + 1) % tableSize;
		}

		if (found)
			throw std::runtime_error("Duplicate items are not allowed.");

		else {
			HT[hIndex].key = key;
			HT[hIndex].value = value;
		}
	}

	bool search1(int key) {
		int hIndex = hashFunction(key);

		bool found = false;
		while (HT[hIndex].key != -1 && !found) {
			if (HT[hIndex].key == key)
				found = true;
			else
				hIndex = (hIndex + 1) % tableSize;
		}

		if (found)
			return true;
		else
			return false;
	}

	void insert2(int key, int value) {
		int hIndex = hashFunction(key);

		bool found = false;
		while (HT[hIndex].key != -1 && !found) {
			if (HT[hIndex].key == key)
				found = true;
			else {
				srand(time(0));
				int randomIndex = 1 + (rand() % tableSize);
				hIndex = (hIndex + randomIndex) % tableSize;
			}	
		}

		if (found)
			throw std::runtime_error("Duplicate items are not allowed.");

		else {
			HT[hIndex].key = key;
			HT[hIndex].value = value;
		}
	}

	void insert3(int key, int value) {
		int hIndex = hashFunction(key);

		bool found = false;
		int i = 1;
		while (HT[hIndex].key != -1 && !found) {
			if (HT[hIndex].key == key)
				found = true;
			else {
				int index = i * i;
				hIndex = (hIndex + index) % tableSize;
				i++;
			}
		}

		if (found)
			throw std::runtime_error("Duplicate items are not allowed.");

		else {
			HT[hIndex].key = key;
			HT[hIndex].value = value;
		}
	}

	bool search3(int key) {
		int hIndex = hashFunction(key);

		bool found = false;
		int i = 1;
		while (HT[hIndex].key != -1 && !found) {
			if (HT[hIndex].key == key)
				found = true;
			else {
				int index = i * i;
				hIndex = (hIndex + index) % tableSize;
				i++;
			}
		}

		if (found)
			return true;
		else
			return false;
	}

	~HashMap() {
		delete[] HT;
	}
};
