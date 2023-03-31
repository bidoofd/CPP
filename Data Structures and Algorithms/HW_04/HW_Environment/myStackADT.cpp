#include "myStackADT.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//sets up myStackADT class
myStackADT::myStackADT(string n, int s)
{
    //sets up name, stack, maxSize, and the topPointer values

    this->name = n;
    this->maxSize = s;
    this->stack = new int[this->maxSize];
    this->topPointer = -1;

    // 1 instruction for each access the variable (5)
    // 1 instruction for each assignment (4)
    // 1 more instruction for setting the array size (1)
    // 1 for accesing the array (1)

    this->instructions = 11;
}

int myStackADT::size()
{
    // 1 instruction for accessing size
    // 1 for returning

    //returns size of the queue
    this->instructions = 2;

    return this->maxSize;
}

int myStackADT::stackSize()
{
    // 1 instruction for accessing topPointer
    // 1 for adding
    // 1 for returning

    //returns size of the queue
    this->instructions = 3;

    return this->topPointer + 1;
}

bool myStackADT::isEmpty()
{
    if(this->topPointer == -1)
    {
        // 1 for accessing variables (1)
        // 1 for comparing values (1)
        // 1 for returning value (1)

        this->instructions = 3;

        return true;
    }
    else
    {
        // 1 for accessing variables (1)
        // 1 for comparing values (1)
        // 1 for returning value (1)

        this->instructions = 3;

        return false;
    }
}

int myStackADT::top()
{
    if(isEmpty() == true)
    {
        // 1 for comparing values (1)
        // 1 for returning value (1)

        this->instructions = 2;

        return -1;
    }
    else
    {
        // 1 for accessing variables (2)
        // 1 for accessing array (1)
        // 1 for comparing values (1)
        // 1 for returning value (1)

        this->instructions = 5;

        return this->stack[this->topPointer];
    }
}

int myStackADT::push(int value)
{
    if(this->topPointer == this->maxSize)
    {
        // 1 for accessing variables (2)
        // 1 for comparing values (1)
        // 1 for returning value (1)

        this->instructions = 4;

        return 0;
    }
    else
    {
        // 1 for accessing variables (6)
        // 1 for accessing array (1)
        // 1 for comparing values (1)
        // 1 for returning value (1)
        // 1 for adding (1)
        // 1 for assigning (2)

        this->instructions = 12;

        this->topPointer = this->topPointer + 1;
        this->stack[this->topPointer] = value;
        return value;
    }
}

int myStackADT::pop()
{
    if(isEmpty() == true)
    {
        // 1 for comparing values (1)
        // 1 for returning value (1)

        this->instructions = 2;

        return -1;
    }
    else
    {
        // 1 for accessing variables (6)
        // 1 for accessing array (2)
        // 1 for comparing values (1)
        // 1 for returning value (1)
        // 1 for subtracting (1)
        // 1 for assigning (2)

        this->instructions = 13;

        int temp = this->stack[this->topPointer];
        this->stack[this->topPointer] = 0;
        this->topPointer = this->topPointer - 1;
        return temp;
    }
}

int myStackADT::getInstructions()
{
    return this->instructions;
}

void myStackADT::resetInstructions()
{
    this->instructions = 0;
}

void myStackADT::writeOutput(ofstream& recFile, string line)
{
    //writes to the output file and ends with a newline
    recFile << line << endl;

    // 1 for writing to file operation

    this->instructions = 1;
}