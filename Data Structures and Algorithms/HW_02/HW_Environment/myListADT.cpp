#include "myListADT.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


//sets up myListADT class
myListADT::myListADT(string n, int s)
{
    //sets up name, array, and base length
    this->name = n;
    this->array = new int[s];
    this->length = s;
}

//checks to see if the list in class is empty
int myListADT::isEmpty()
{
    //if the pointer position of the array is 0 then return 1
    if(this->pointer == 0)
    {
        return 1;
    }

    // Otherwise return 0
    else
    {
        return 0;
    }
}


// returns the size of the list at the time
int myListADT::size()
{
    //returns size of created list
    return this->pointer;
}

//returns value at the index
int myListADT::at(int index)
{
    //if the inputted index value is greater than 0 and less than the pointer, it returns the value stored at the index
    //  - When the index value is greater than or equal to 0, that means that it is a valid index to exist
    //  - If it is less than the pointer then the index exists inside of the array
    if(index >= 0 && index < this->pointer)
    {
        return this->array[index];
    }

    // return -1 if index does not exist
    return -1;
}


//sets value at the index
int myListADT::set(int index, int object)
{
    //Same IF scenario as at function
    if(index >= 0 && index < this->pointer)
    {
        // stores the old value inside of a temporary variable
        int oldObj = this->array[index];
        // stores the new value into the selected index
        this->array[index] = object;
        // returns the old value
        return oldObj;
    }

    // return -1 if index does not exist
    return -1;
}


//inserts a value at a specific index in the list
int myListADT::insert(int index, int object)
{
    // Variables for counts
    int countIterations = 0;
    int countOperations = 0;

    //If the positional size is the same as max size, return -2
    if(this->pointer == this->length)
    {
        // Adding 4
        //  - 1 for accessing pointer length
        //  - 1 for accessing length
        //  - 1 for comparing pointer length and length
        //  - 1 for returning a value
        countOperations = countOperations + 4;
        return -2;
    }
    //If statement to see if index is valid
    if(index >= 0 && index <= this->pointer)
    {
        // Adding 4
        //  - 1 for accessing pointer length
        //  - 1 for comparing index to 0
        //  - 1 for comparing index to pointer length
        //  - 1 for comparing both flags 
        countOperations = countOperations + 4;

        //For loop to start at position of the pointer to shift every element to the right before insertion
        for(int a = this->pointer; a >= index; a--)
        {
            this->array[a] = this->array[a-1];
            countIterations = countIterations + 1;
        }

        // * FOR LOOP
        // 1 for setting variable a equal to pointer length
        // 1 for accessing pointer length
        // 1 for comparing variable a to the index
        // 1 for a--

        // +4

        // 1 for comparison
        // 1 for a--

        // +(2*n)

        // 1 for subtracting

        // +1
        // * END FOR LOOP

        // ** INSIDE FOR LOOP
        // 1 for accessing array
        // 1 for accessing array value
        // 1 for accessing array again
        // 1 for accessing array value before
        // 1 for assigning current array value for previous

        // +5

        // 1 for adding to countIterations
        // 1 for assigning new countIterations value

        // +2
        // ** END INSIDE FOR LOOP

        //4 + (2 * n) + 1 + 5 + 2

        countOperations = countOperations + 12 + (2 * this->pointer);

        // stores the object at inputted index
        this->array[index] = object;
        // adds 1 to positional pointer
        this->pointer = this->pointer + 1;
        //returns the pointer

        // 1 for accessing array
        // 1 for accessing array index
        // 1 for assigining array index with the object

        // 1 for accessing pointer
        // 1 for accessing pointer again
        // 1 for adding to pointer
        // 1 for assigning old pointer with new

        countOperations = countOperations + 7;

        cout << "The number of iterations that happened in the loop is: " << countIterations << "." << endl;
        cout << "The number of primitive operations that happened is: " << countOperations << "." << endl;

        return this->pointer;
    }

    // return -1 if index does not exist
    return -1;
}

int myListADT::erase(int index)
{
    // Variables for counts
    int countIterations = 0;
    int countOperations = 0;

    // If the pointer size is 0, then returns -2
    if(this->pointer == 0)
    {
        // Adding 4
        //  - 1 for accessing pointer length
        //  - 1 for accessing length
        //  - 1 for comparing pointer length and length
        //  - 1 for returning a value
        countOperations = countOperations + 4;
        return -2;
    }

    // Checks to see if the index exists
    if(index >= 0 && index <= this->pointer)
    {
        // Adding 4
        //  - 1 for accessing pointer length
        //  - 1 for comparing index to 0
        //  - 1 for comparing index to pointer length
        //  - 1 for comparing both flags 
        countOperations = countOperations + 4;

        // Stores the erasing value in a variable
        int erasedNum = this->array[index];

        // Adding 3
        //  - 1 for accessing array
        //  - 1 for accessing array index
        //  - 1 for assigning value to erasedNum

        countOperations = countOperations + 3;

        // For loop to shift elements to the left
        for(int a = index; a < this->pointer; a++)
        {
            this->array[a] = this->array[a+1];
        }

        // * FOR LOOP
        // 1 for setting variable a equal to index
        // 1 for comparing a to the index
        // 1 for a--

        // +4

        // 1 for comparison
        // 1 for a++

        // +(2*n-1)

        // 1 for subtracting

        // +1
        // * END FOR LOOP

        // ** INSIDE FOR LOOP
        // 1 for accessing array
        // 1 for accessing array value
        // 1 for accessing array again
        // 1 for accessing array value before
        // 1 for assigning current array value for previous

        // +5

        // 1 for adding to countIterations
        // 1 for assigning new countIterations value

        // +2
        // ** END INSIDE FOR LOOP

        // Decreases pointer size

        countOperations = countOperations + 5 + (2 * this->pointer - 1);

        this->pointer = this->pointer - 1;

        // 1 for accessing pointer
        // 1 for accessing pointer again
        // 1 for adding to pointer
        // 1 for assigning old pointer with new

        countOperations = countOperations + 4;

        // return erased value

        cout << "The number of iterations that happened in the loop is: " << countIterations << "." << endl;
        cout << "The number of primitive operations that happened is: " << countOperations << "." << endl;

        return erasedNum;
    }

    // return -1 if index does not exist

    return -1;
}

void myListADT::printList(ofstream& file)
{
    //prints out contents of list
    for(int a = 0; a < this->pointer; a++)
    {
        cout << "[" << a << "]" << ": " << this->array[a] << endl;
    }
}

void myListADT::writeOutput(ofstream& recFile, string line)
{
    //writes to the output file and ends with a newline
    recFile << line << endl;
}