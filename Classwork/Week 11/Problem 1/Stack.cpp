#include "Stack.h"
#include <iostream>
#include <math.h>

Stack::Stack()
{
    this->top = -1;
    for(int a = 0; a < MAX-1; a++)
    {
        myStack[a] = 0;
    }
}

bool Stack::push(int x)
{
    if(this->isFull() == true)
    {
        cout << "Stack Overflow" << endl;
        return false;
    }
    else
    {
        this->top = this->top + 1;
        myStack[this->top] = x;
        cout << "Successful push" << endl;
        return true;
    }
}

int Stack::pop()
{
    if(this->isEmpty() == true)
    {
        cout << "Stack Underflow" << endl;
        return 0;
    }
    else
    {
        int temp = myStack[this->top];
        myStack[this->top] = 0;
        this->top = this->top - 1;
        cout << temp << endl;
        return temp;
    }
}

bool Stack::isEmpty()
{
    if(this->top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack::isFull()
{
    if(this->top == 99)
    {
        return true;
    }
    else
    {
        return false;
    }
}