#include "Saving.h"
#include <iostream>

Saving::Saving()
{
    
}

Saving::Saving(string t, string n, string od, double bal, Customer *id)
{
    type = t;
    num = n;
    openDate = od;
    balance = bal;
    cusID = id;
}

string Saving::getType()
{
    return type;
}

string Saving::getNumber()
{
    return num;
}

string Saving::getOpenDate()
{
    return openDate;
}

double getBalance()
{
    return balance;
}

void deposit(double amount)
{
    balance = balance + amount;
}

void withdraw(double amount)
{
    balance = balance - amount;
}

Customer *Saving::getCustomerID()
{
    return id;
}