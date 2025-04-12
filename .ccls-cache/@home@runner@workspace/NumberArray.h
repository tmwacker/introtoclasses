//Programmer: Timothy Wacker

#ifndef NUMBERARRAY_H
#define NUMBERARRAY_H

const int MAX_SIZE = 10;  
const double DEFAULT_VALUE = 10000.0;  

class NumberArray {
private:
    int size;  
    double* arr; 

public:
    NumberArray(int size = MAX_SIZE);

    ~NumberArray();

    // Store value at specific index
    void storeNumber(int index, double value);

    // Retrieve value from array
    double getNumber(int index) const;

    // Get minimum value from the array
    double getMin() const;

    // Get maximum value from the array
    double getMax() const;

    //  average of array elements
    double getAverage() const;

    // Display all values in the array
    void displayArray() const;
};

#endif