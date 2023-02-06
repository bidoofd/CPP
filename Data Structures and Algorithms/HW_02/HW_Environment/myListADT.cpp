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
    //If the positional size is the same as max size, return -2
    if(this->pointer == this->length)
    {
        return -2;
    }
    //If statement to see if index is valid
    if(index >= 0 && index <= this->pointer)
    {
        //For loop to start at position of the pointer to shift every element to the right before insertion
        for(int a = this->pointer; a >= index; a--)
        {
            cout << "index: " << a << endl;
            this->array[a] = this->array[a-1];
        }
        // stores the object at inputted index
        this->array[index] = object;
        // adds 1 to positional pointer
        this->pointer = this->pointer + 1;
        //returns the pointer
        return this->pointer;
    }

    // return -1 if index does not exist
    return -1;
}

int myListADT::erase(int index)
{
    // If the pointer size is 0, then returns -2
    if(this->pointer == 0)
    {
        return -2;
    }

    // Checks to see if the index exists
    if(index >= 0 && index <= this->pointer)
    {
        // Stores the erasing value in a variable
        int erasedNum = this->array[index];
        // For loop to shift elements to the left
        for(int a = index; a > index; a--)
        {
            this->array[a] = this->array[a-1];
        }

        // Decreases pointer size
        this->pointer = this->pointer - 1;

        // return erased value
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