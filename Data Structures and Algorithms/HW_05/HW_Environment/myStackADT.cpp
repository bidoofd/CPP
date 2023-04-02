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

    // 1 instruction for each access the variable (2)
    // 1 instruction for each assignment (2)

    this->instructions = 4;
}

int myStackADT::size()
{
    Node *temp;
    int count = 0;
    int extraInstructions = 0;
    if(isEmpty())
    {
        // 1 instruction for each assignment (3)
        // 1 for creating temp node (1)
        // 1 for empty operation (1)

        this->instructions = 5;
        return -1;
    }
    else
    {
        temp = this->topPointer;
        extraInstructions = extraInstructions + 2;
        while(temp != NULL)
        {
            count++;
            temp = temp->next;
            extraInstructions = extraInstructions + 5;
        }
        extraInstructions++;
    }

    // 1 instruction for each assignment (4 + x)
    // 1 for creating temp node (1)
    // 1 for empty operation (1)
    // 1 for comparison (x)
    // 1 for accessing variables (1 + x)
    // 1 for adding to count and assigning (x)

    this->instructions = 7 + extraInstructions;
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
        // 1 for empty function

        this->instructions = 3;

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
        // 1 for creating new node (1)
        // 1 for comparing values (1)
        // 1 for returning value (1)

        this->instructions = 3;
        return -1;
    }
    else
    {
        temp->data = value;
        temp->next = this->topPointer;
        this->topPointer = temp;

        // 1 for creating new node (1)
        // 1 for comparing values (1)
        // 1 for returning value (1)
        // 1 for accessing variables (4)
        // 1 for assigning variables (3)

        this->instructions = 10;
        return this->topPointer->data;
    }
}

int myStackADT::pop()
{
    if(isEmpty() == true)
    {
        // 1 for comparing values (1)
        // 1 for returning value (1)
        // 1 for function empty

        this->instructions = 3;

        return -1;
    }
    else
    {
        Node *temp;
        temp = this->topPointer;
        int tempValue = temp->data;
        this->topPointer = this->topPointer->next;

        // deletes node and frees up memory
        free(temp);

        // 1 for creating new node (1)
        // 1 for comparing values (1)
        // 1 for returning value (1)
        // 1 for accessing variables (4)
        // 1 for assigning variables (3)
        // 1 fpr free operation (1)

        this->instructions = 11;
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