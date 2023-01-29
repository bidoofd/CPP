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