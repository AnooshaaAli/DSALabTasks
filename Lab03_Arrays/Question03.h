#pragma once
#include<iostream>
using namespace std;

float maxAverage(int arr[], int n, int k) {
	float largest = 0.0;
	float average = 0.0;
	for (int count = 0; count + k <= n; count++) {
		average = 0.0;
		for (int i = count; i < k+count; i++) {
			average = average + (float)arr[i];
		}
		average = average / k;
		if (average > largest) {
			largest = average;
		}
	}
	return largest;
}
