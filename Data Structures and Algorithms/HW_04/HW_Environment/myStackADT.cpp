#include "myStackADT.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//sets up myListADT class
myStackADT::myStackADT(string n, int s)
{
    this->name = n;
    this->maxSize = s;
    this->stack = new int[this->maxSize];
    this->topPointer = -1;
}

int myStackADT::size()
{
    return this->maxSize;
}

bool myStackADT::isEmpty()
{
    if(this->topPointer == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int myStackADT::top()
{
    if(isEmpty() == true)
    {
        return -1;
    }
    else
    {
        return this->stack[this->topPointer];
    }
}

int myStackADT::push(int value)
{
    if(this->topPointer == this->maxSize)
    {
        return 0;
    }
    else
    {
        this->topPointer = this->topPointer + 1;
        this->stack[this->topPointer] = value;
        return value;
    }
}

int myStackADT::pop()
{
    if(isEmpty() == true)
    {
        return -1;
    }
    else
    {
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