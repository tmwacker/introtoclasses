// Programmer: Timothy Wacker

#include <iostream>
#include <random>
#include "NumberArray.h"

int main() {
    // Test the default 
    NumberArray arr1;
    std::cout << "Array from default constructor: ";
    arr1.displayArray();

    // Test constructor with a custom size
    NumberArray arr2(15);
    std::cout << "Array from constructor with size 15: ";
    arr2.displayArray();

    // Fill array with random values between 1.0 and 100.0
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(1.0, 100.0);
    for (int i = 0; i < 15; i++) {
        arr2.storeNumber(i, dis(gen));
    }
    std::cout << "Array after filling with random numbers: ";
    arr2.displayArray();

    // out-of-bounds access
    arr2.storeNumber(20, 50.0);  

    // Retrieve and display values at specific indices
    std::cout << "Access item at index 5: " << arr2.getNumber(5) << std::endl;
    std::cout << "Access item at index 20 (out of bounds): " << arr2.getNumber(20) << std::endl;

    // Display minimum, maximum, and average
    std::cout << "The minimum value in the array is: " << arr2.getMin() << std::endl;
    std::cout << "The maximum value in the array is: " << arr2.getMax() << std::endl;
    std::cout << "The average of the values in the array is: " << arr2.getAverage() << std::endl;

    return 0;
}