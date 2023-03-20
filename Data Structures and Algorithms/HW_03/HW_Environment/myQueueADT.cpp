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
    //returns size of the queue
    return this->size;
}

int myQueueADT::emptyFlag()
{
    // If the front and rear position are equal to -1, then the queue is empty
    if(this->front == -1 && this->rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int myQueueADT::fullFlag()
{
    // Checks to see if front is next to the rear, then the queue is full
    if((this->rear + 1) % this->size == front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int myQueueADT::firstInQ()
{
    //As long as queue is not empty, return the first value in the queue
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
    //If the queue is full, return -1
    if(fullFlag() == 1)
    {
        return -1;
    }
    // If the queue is empty, set the rear and front to 0, then set the value to either front or rear. return inserted value
    else if(emptyFlag() == 1)
    {
        this->front = 0;
        this->rear = 0;
        this->array[rear] = num;
        return num;
    }
    // Otherwise the queue is not empty. Find the position of the newly inserted value and returns it
    else
    {
        this->rear = (this->rear + 1) % this->size;
        this->array[rear] = num;
        return num;
    }
}

int myQueueADT::dequeue()
{
    // If queue is empty, return -1
    if(emptyFlag() == 1)
    {
        return -1;
    }
    // Checks to see if there is only 1 value. If there is reset the queue and return dequeued value
    else if(this->front == this->rear)
    {
        int temp = this->array[this->front];
        this->front = -1;
        this->rear = -1;
        return temp;
    }
    // Otherwise dequeue value from the front
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