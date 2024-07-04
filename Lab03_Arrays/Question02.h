#include <iostream>
#include <cmath>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

bool isPerfectSquare(int num) {
    int sqrtNum = sqrt(num);
    return (sqrtNum * sqrtNum == num);
}

bool isSquareful(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int num = arr[i] + arr[i + 1];
        if (!isPerfectSquare(num)) {
            return false;
        }
    }
    return true;
}

void generateUniquePermutations(int arr[], int size, int index, int& count) {
    if (index == size) {
        if (isSquareful(arr, size)) {
            count++;
        }
        return;
    }

    for (int i = index; i < size; i++) {
        if (i == index || arr[i] != arr[index]) {
            swap(arr[i], arr[index]);
            generateUniquePermutations(arr, size, index + 1, count);
            swap(arr[i], arr[index]); 
        }
    }
}

int findUniquePermutations(int arr[], int size) {
    int count = 0;
    generateUniquePermutations(arr, size, 0, count);
    return count;
}
