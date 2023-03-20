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

    // 1 instruction for each access the variable (5)
    // 1 instruction for each assignment (5)
    // 1 more instruction for setting the array size

    cout << "The number of instructions executed is 11." << endl;
}

int myQueueADT::qSize()
{
    // 1 instruction for accessing size
    // 1 for returning

    cout << "The number of instructions executed is 2." << endl;

    //returns size of the queue
    return this->size;

}

int myQueueADT::emptyFlag()
{
    // If the front and rear position are equal to -1, then the queue is empty
    if(this->front == -1 && this->rear == -1)
    {
        // 1 for accessing variables (2)
        // 1 for comparing values (3)
        // 1 for returning value (1)

        cout << "The number of instructions executed is 6." << endl;
        return 1;
    }
    else
    {
        // 1 for accessing variables (2)
        // 1 for comparing values (3)
        // 1 for returning value (1)

        cout << "The number of instructions executed is 6." << endl;
        return 0;
    }
}

int myQueueADT::fullFlag()
{
    // Checks to see if front is next to the rear, then the queue is full
    if((this->rear + 1) % this->size == front)
    {
        // 1 for accessing variables (2)
        // 1 for comparing values (1)
        // 1 for evaluating values (2)
        // 1 for returning value (1)

        cout << "The number of instructions executed is 6." << endl;
        return 1;
    }
    else
    {
        // 1 for accessing variables (2)
        // 1 for comparing values (1)
        // 1 for evaluating values (2)
        // 1 for returning value (1)

        cout << "The number of instructions executed is 6." << endl;

        return 0;
    }
}

int myQueueADT::firstInQ()
{
    //As long as queue is not empty, return the first value in the queue
    if(emptyFlag() != 1)
    {
        // 1 for accessing variables (2)
        // 1 for empty flag operation (1)
        // 1 for comparison (1)
        // 1 for returning value (1)

        cout << "The number of instructions executed is 5." << endl;

        return this->array[this->front];
    }
    else
    {
        // 1 for empty flag operation (1)
        // 1 for comparison (1)
        // 1 for returning value (1)

        cout << "The number of instructions executed is 3." << endl;

        return -1;
    }
}

int myQueueADT::enqueue(int num)
{
    //If the queue is full, return -1
    if(fullFlag() == 1)
    {
        // 1 for full flag operation (1)
        // 1 for comparison (1)
        // 1 for returning value (1)

        cout << "The number of instructions executed is 3." << endl;

        return -1;
    }
    // If the queue is empty, set the rear and front to 0, then set the value to either front or rear. return inserted value
    else if(emptyFlag() == 1)
    {
        this->front = this->rear = 0;
        this->array[rear] = num;

        // 1 for emptyFlag operation (1)
        // 1 for comparison (1)
        // 1 for accessing values (3)
        // 1 for assigning values (3)
        // 1 for indexing array (1)
        // 1 for returning value (1)

        cout << "The number of instructions executed is 10." << endl;

        return num;
    }
    // Otherwise the queue is not empty. Find the position of the newly inserted value and returns it
    else
    {
        this->rear = (this->rear + 1) % this->size;
        this->array[rear] = num;

        // 1 for flag operation (2)
        // 1 for comparison (2)
        // 1 for accessing values (4)
        // 1 for assigning values (2)
        // 1 for indexing array (1)
        // 1 for operation evaluation (2)
        // 1 for returning value (1)

        cout << "The number of instructions executed is 14." << endl;

        return num;
    }
}

int myQueueADT::dequeue()
{
    // If queue is empty, return -1
    if(emptyFlag() == 1)
    {

        // 1 for empty flag operation (1)
        // 1 for comparison (1)
        // 1 for returning value (1)

        cout << "The number of instructions executed is 3." << endl;
        return -1;
    }
    // Checks to see if there is only 1 value. If there is reset the queue and return dequeued value
    else if(this->front == this->rear)
    {
        int temp = this->array[this->front];
        this->front = this->rear = -1;

        // 1 for emptyFlag operation (1)
        // 1 for comparison (1)
        // 1 for accessing values (6)
        // 1 for assigning values (3)
        // 1 for indexing array (1)
        // 1 for returning value (1)

        cout << "The number of instructions executed is 13." << endl;

        return temp;
    }
    // Otherwise dequeue value from the front
    else
    {
        int temp = this->array[this->front];
        this->front = (this->front + 1) % this->size;

        // 1 for flag operation (1)
        // 1 for comparison (2)
        // 1 for accessing values (7)
        // 1 for assigning values (2)
        // 1 for indexing array (1)
        // 1 for operation evaluation (2)
        // 1 for returning value (1)

        cout << "The number of instructions executed is 16." << endl;

        return temp;
    }
}

void myQueueADT::writeOutput(ofstream& recFile, string line)
{
    //writes to the output file and ends with a newline
    recFile << line << endl;

    // 1 for writing to file operation

    cout << "The number of instructions executed is 1." << endl;
}