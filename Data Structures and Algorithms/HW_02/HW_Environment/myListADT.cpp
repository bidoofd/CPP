#include "myListADT.h"

using namespace std;

myListADT::myListADT(string n, int s)
{
    this->name = n;
    this->array = new int[s];
    this->length = s;
}

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

int myListADT::size()
{
    return this->length;
}

int myListADT::at(int index)
{
    if(this->length != 0)
    {
        return this->array[index];
    }
    return -1;
}

int myListADT::set(int index, int object)
{
    if(this->array[index] > 0 && this->length != 0)
    {
        int oldObj = this->array[index];
        this->array[index] = object;
        return oldObj;
    }
    return -1;
}

int myListADT::insert(int index, int object)
{
    if(this->pointer == this->length)
    {
        return -2;
    }
}