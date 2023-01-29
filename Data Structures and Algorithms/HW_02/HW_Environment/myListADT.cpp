#include "myListADT.h"

using namespace std;


//sets up myListADT class
myListADT::myListADT(string n, int s)
{
    this->name = n;
    this->array = new int[s];
    this->length = s;
}

//checks to see if the list in class is empty
int myListADT::isEmpty()
{
    if(this->length == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


// returns the size of the list at the time
int myListADT::size()
{
    return this->pointer;
}

//returns value at the index
int myListADT::at(int index)
{
    if(index >= 0 && index < this->pointer)
    {
        return this->array[index];
    }
    return -1;
}


//sets value at the index
int myListADT::set(int index, int object)
{
    if(index >= 0 && index < this->pointer)
    {
        int oldObj = this->array[index];
        this->array[index] = object;
        return oldObj;
    }
    return -1;
}


//inserts a value at a specific index in the list
int myListADT::insert(int index, int object)
{
    if(this->pointer == this->length)
    {
        return -2;
    }
    if(index >= 0 && index <= this->pointer)
    {
        for(int a = this->pointer; a > index; a--)
        {
            this->array[a] = this->array[a-1];
        }
        this->array[index] = object;
        this->pointer = this->pointer + 1;
        return this->pointer;
    }
    return -1;
}