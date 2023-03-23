#include "myStackADT.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//sets up myListADT class
myStackADT::myStackADT(string n, int s)
{
    this->name = n;
    this->stack = new int[s];
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
    return this->topPointer;
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