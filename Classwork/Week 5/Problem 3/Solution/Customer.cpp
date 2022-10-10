#include "Customer.h"
#include <iostream>
.
Customer::Customer()
{
    
}
Customer::Customer(string i, string p)
{
    id = i;
    pin = p;
}

string Customer::getID()
{
    return id;
}

string Customer::getPIN()
{
    return pin;
}

