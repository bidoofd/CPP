#include "myQueueADT.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//sets up myListADT class
myQueueADT::myQueueADT(string n, int s)
{
    //sets up name, array, and base length
    this->front = this->rear = -1;
    this->size = s;
    this->name = n;
    this->array = new int[s];
}

int myQueueADT::qSize()
{
    return this->size;
}

bool myQueueADT::emptyFlag()
{
    if(this->front == -1 && this->rear == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool myQueueADT::fullFlag()
{
    if((this->rear + 1) % this->size == front)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int myQueueADT::firstInQ()
{
    if(emptyFlag() != 1)
    {
        return this->array[this->front];
    }
    else
    {
        return -1;
    }
}

int myQueueADT::enqueue(int num)
{
    if(fullFlag() == 1)
    {
        return -1;
    }
    else if(emptyFlag() == 1)
    {
        this->front = 0;
        this->rear = 0;
        this->array[rear] = num;
        return num;
    }
    else
    {
        this->rear = (this->rear + 1) % this->size;
        this->array[rear] = num;
        return num;
    }
}

int myQueueADT::dequeue()
{
    if(emptyFlag() == 1)
    {
        return -1;
    }
    else if(this->front == this->rear)
    {
        int temp = this->array[this->front];
        this->front = -1;
        this->rear = -1;
        return temp;
    }
    else
    {
        int temp = this->array[this->front];
        this->front = (this->front + 1) % this->size;
        return temp;
    }
}

void myQueueADT::writeOutput(ofstream& recFile, string line)
{
    //writes to the output file and ends with a newline
    recFile << line << endl;
}