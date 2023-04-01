#include "myStackADT.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//sets up myStackADT class
myStackADT::myStackADT(string n)
{
    //sets up name, stack, maxSize, and the topPointer values
    this->name = n;
    this->topPointer = NULL;

    // 1 instruction for each access the variable (5)
    // 1 instruction for each assignment (4)
    // 1 more instruction for setting the array size (1)
    // 1 for accesing the array (1)

    this->instructions = 11;
}

int myStackADT::size()
{
    Node *temp;
    int count = 0;
    if(isEmpty())
    {
        return -1;
    }
    else
    {
        temp = this->topPointer;
        while(temp != NULL)
        {
            count++;
        }
    }
    return count;
}

bool myStackADT::isEmpty()
{
    if(this->topPointer == NULL)
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

        return this->topPointer->data;
    }
}

int myStackADT::push(int value)
{
    Node* temp = new Node(value);
    if(!temp)
    {
        return -1;
    }
    else
    {
        temp->data = value;
        temp->next = this->topPointer;
        this->topPointer = temp;
        return this->topPointer->data;
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
        Node *temp;
        temp = this->topPointer;
        int tempValue = temp->data;
        this->topPointer = this->topPointer->next;
        free(temp);
        return tempValue;
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