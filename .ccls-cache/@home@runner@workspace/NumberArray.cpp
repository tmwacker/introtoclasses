//Programmer Timothy Wacker

#include "NumberArray.h"
#include <iostream>
#include <iomanip>

// Initialize the array with zeros
NumberArray::NumberArray(int size) {
    this->size = size;
    arr = new double[size]{};  
}

NumberArray::~NumberArray() {
    delete[] arr;  // Deallocate memory
}

// Store a number in the array 
void NumberArray::storeNumber(int index, double value) {
    if (index >= 0 && index < size) {
        arr[index] = value;
    }
}

// Retrieve a number from the array 
double NumberArray::getNumber(int index) const {
    if (index >= 0 && index < size) {
        return arr[index];
    }
    return DEFAULT_VALUE;  
}

//  minimum value in the array
double NumberArray::getMin() const {
    double min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Get the maximum value in the array
double NumberArray::getMax() const {
    double max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

//  return the average of all elements in the array
double NumberArray::getAverage() const {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

// Show all elements in the array
void NumberArray::displayArray() const {
    for (int i = 0; i < size; i++) {
        std::cout << std::fixed << std::setprecision(1) << arr[i] << " ";
    }
    std::cout << std::endl;
}