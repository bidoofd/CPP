#include "Customer.h"
#include <iostream>

Customer::Customer()
{

}

Customer::Customer(string n, int i, int p, string d)
{
    cName = n;
    cID = i;
    cPin = p;
    cAccDate;
}

string Customer::cGetName()
{
    return cName;
}

int Customer::cGetID()
{
    return cID;
}

int Customer::cGetPin()
{
    return cPin;
}

void Customer::cDeposit()
{
    
}

void Customer::cWithdraw(int amount, string accType, string accDate, int accID)
{
    aAccount = new Account(amount, accType, accDate, accID);
    aAccount->incAcc();
}

void Customer::cPrint()
{
    cout << "Name: " << cGetName() << endl;
    cout << "ID: " << cGetID() << endl;
    cout << "PIN: " << cGetPin() << endl;
}