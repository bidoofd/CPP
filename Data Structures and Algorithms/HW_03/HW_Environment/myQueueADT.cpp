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

int myQueueADT::emptyFlag()
{
    if(this->front == -1 && this->rear == -1)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int myQueueADT::fullFlag()
{
    if((this->rear + 1) % this->size == front)
    {
        return 1;
    }
    else
    {
        return -1;
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
        //int firstInQ();
        //int enqueue(int num);
        //int dequeue();

        //void writeOutput(ofstream& file, string line);