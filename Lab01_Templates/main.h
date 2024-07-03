//
// pch.h
//
#pragma once
#include "gtest/gtest.h"
#include<iostream>
using namespace std;

/*  *********************Task-1*********************/

template <typename T, size_t size>

//this function will check duplicates
bool isDuplicate( const T& value, const T(&arr)[size], size_t currentSize) {
    for (size_t i = 0; i < currentSize; i++) {
        if (arr[i] == value) {
            return true;
        }
    }

    return false;
}

template <typename T, size_t size>

//this function will remove duplicates
size_t RemoveDups(T(&arr)[size]) {
    size_t count = 0;
    for (size_t i = 0; i < size; i++) {
        if (!isDuplicate(arr[i], arr, i)) {
            arr[count] = arr[i];
            count++;
        }
    }
    return count;
}


/*  *********************Task-2*********************/


template <typename T, size_t size>
void Rotate(T(&array)[size], size_t k) {

    T result[size];          // temporary array tpo store the resultant array after rotation
    for (size_t i = 0; i < k; i++) {
        for (size_t j = 0; j < size - 1; j++) {
            result[j] = array[j + 1];
        }
        result[size - 1] = array[0];
        for (size_t k = 0; k < size; k++) {
            array[k] = result[k];
        }
    }
}


/*  *********************Task-3*********************/

template <typename T>
class Container {
private:
    T* values;
    size_t capacity;
    size_t counter;

public:
    Container(size_t C) {
        capacity = C;
        counter = 0;
        values = new T[capacity];
    }

    bool isFull() const {
        if (counter == capacity) {
            return true;
        }
        return false;
    }

    void insert(const T& value) {

        if (!isFull()) {
            values[counter] = value;
            counter++;
        }

    }

    bool search(const T& val) const {

        for (size_t i = 0; i < counter; i++) {
            if (values[i] == val) {
                return true;
            }
        }

        return false;
    }

    void remove(const T& val) {

        for (size_t i = 0; i < counter; i++) {
            if (values[i] == val) {
                counter = counter - 1;
                for (size_t k = i; k < counter; k++) {
                    values[i] = values[i + 1];
                }
                break;
            }
        }
    }

    void print() const {

        for (size_t i = 0; i < counter; i++) {
            cout << values[i] << " ";
        }
        cout << endl;
    }

    ~Container() {
        delete[] values;
    }

};

/*  *********************Task-4*********************/

template <typename T, size_t size>
std::pair<int, int> findTargetIndices(T(&students)[size], T target) {

    // in case sum is not equal to target means both the indices will be -1
    int array[2] = {-1,-1};

    //checking the sum
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if ((students[i] + students[j]) == target) {
                array[0] = i;
                array[1] = j;
                return std::make_pair(array[0], array[1]);;
            }
        }
    }
    return std::make_pair(array[0], array[1]);
}
