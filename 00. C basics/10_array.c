//  Arrays in C
// An array is a collection of elements of the same type stored in contiguous memory locations.

// Declaration
// type arrayName[arraySize];

// type       : Data type of array elements (eg: int, float, char).
// arrayName  : Name of the array.
// arraySize  : Number of elements in the array.

#include <stdio.h>

int sum(int* arr, int size){
        // passing array to function using pointer
        // loop through fuction
    int s = 0;
    for(int i=0; i<size; i++){
        s+=arr[i];
    }
    return s;
}


int main(){
    int arr[5] = {10, 20, 30, 40, 50};  // Array with 5 elements
        // Initialization

    int firstElement = arr[0];  // will be 10
        // Accessing Elements
   
    // Arrays in C have a fixed size, and the size must be a constant expression.

    int size = sizeof(arr)/sizeof(int);
        // getting array size
    
    int s = sum(arr, size);

    return 0;
}