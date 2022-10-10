#include "Checking.h"
#include <iostream>

Checking::Checking()
{
    
}

Checking::Checking(string t, string n, string od, double bal, Customer *id)
{
    type = t;
    num = n;
    openDate = od;
    balance = bal;
    cusID = *id;
}

string Checking::getType()
{
    return type;
}

string Checking::getNumber()
{
    return num;
}

string Checking::getOpenDate()
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

Customer::getCustomerID()
{
    return cusID;
}
Checking::Checking()
{

}

Checking::Checking(string t, string n, string od, double bal, Customer *id)
{
    type = t;
    num = n;
    openDate = od;
    balance = bal;
    cusID = *id;
}

string Checking::getType()
{
    return type;
}

string Checking::getNumber()
{
    return num;
}

string Checking::getOpenDate()
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

Customer::getCustomerID()
{
    return cusID;
}

Customer *Checking::getCustomerID()
{
    return id;
}