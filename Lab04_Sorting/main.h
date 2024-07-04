#pragma once
#include "gtest/gtest.h"
#include<iostream>
#include<string>
using namespace std; 

//------------------------------------------------------------- Question: 01 -----------------------------------------------------------------

struct StudentRecord {
	int studentID;
	std::string name;
	float GPA;
};

void insertionSortStudents(StudentRecord arr[], int size) {
	int i, j;
	for (i = 1; i < size; i++) {
		float temp = arr[i].GPA;
		for (j = i; j > 0 && temp < arr[j - 1].GPA; j--) {
			arr[j] = arr[j - 1];
		}
		arr[j].GPA = temp;
	}
}

//------------------------------------------------------------- Question: 02 ------------------------------------------------------------------

struct EmployeeRecord {
	int employeeID;
	string name;
	float salary;
};

void swap(EmployeeRecord& a, EmployeeRecord& b) {
	EmployeeRecord temp = a;
	a = b;
	b = temp;
}

int partition(EmployeeRecord arr[], int low, int high) {
	EmployeeRecord PivotPoint = arr[low];
	float pivotValue = PivotPoint.salary;
	int i = low;
	int j = high + 1;

	while (true) {

		//iterate i until arr[i].salary becomes greater than pivotValue
		while (i <= high && arr[i].salary < pivotValue) {
			i++;
		}

		//iterate j until arr[i].salary becomes less than pivotValue
		do {
			j--;
		} while (arr[j].salary > pivotValue);

		//if i becomes greater than or equal to the index j, then swap the pivotPoint with the employee at position j
		if (i >= j) {
			break;
		}
		
		//else first swap the employee at index i with emloyee at index j and then swap the pivotPoint
		swap(arr[i], arr[j]);
	}

	swap(PivotPoint, arr[j]);  //swapping the pivot point 

	//here j will be our next pivotPoint
	return j;
}

void iterativeQuickSortEmployees(EmployeeRecord arr[], int size) {
	int* stack = new int[size];
	int top = 0;

	stack[top] = 0;  //low
	top++;
	stack[top] = size - 1;  //high

	//it will sort until the stack gets empty
	while (top >= 0) {
		int high = stack[top];
		top--;
		int low = stack[top];
		top--;

		int pivotPoint = partition(arr, low, high);

		if (pivotPoint - 1 > low) {
			stack[++top] = low;
			stack[++top] = pivotPoint - 1;
		}

		if (pivotPoint + 1 < high) {
			stack[++top] = pivotPoint + 1;
			stack[++top] = high;
		}
	}

	//deleting the dynamic memory
	delete[] stack; 
}

//-------------------------------------------------------------- Question: 03 --------------------------------------------------------------

void bubbleSort(int grades[], int numStudents) {
	for (int i = 0; i < numStudents; i++) {
		for (int j = i; j < numStudents-1; j++) {
			if (grades[j] > grades[j + 1]) {
				int temp = grades[j];
				grades[j] = grades[j + 1];
				grades[j + 1] = temp;
			}
		}
	}
}

int binarySearch(int grades[], int numStudents, int StudentID) {
	int low = 0;
	int high = numStudents - 1;
	int mid = (low + high) / 2;

	while (low != high) {
		if (grades[mid] == StudentID) {
			return grades[mid];
		}
		else if (grades[low] == StudentID) {
			return grades[low];
		}
		else if (grades[high] == StudentID) {
			return grades[high];
		}
		else if (grades[mid] < StudentID) {
			low = mid;
			mid = (low + high) / 2;
		}
		high = mid;
		mid = (low + high) / 2;
	}
	return -1;
}
