#include "Account.h"
#include <iostream>
#include <string>

using namespace std;

Account::Account(int vAmount, string vType, string vDate, int vAccID)
{
    aAmount = vAmount;
    aType = vType;
    aDate = vDate;
    aAccID = vAccID;
}

int Account::aGetAmount()
[
    return aAmount;
]

string Account::aGetType()
{
    return aType;
}

void Account::incAcc()
{
    accNum++;
}