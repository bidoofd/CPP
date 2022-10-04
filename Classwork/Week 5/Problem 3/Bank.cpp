#include "Bank.h"
#include <iostream>
#include <string>
#include <random>
using namespace std;

Bank::Bank(string bankName)
{
    bName = bankName;
    cCustomer = NULL;
}

void offerService()
{
    string choice;
    int amount;

    cout << "What do you want to do?" << endl;
    cout << "1. Deposit" << endl;
    cout << "2. Withdraw" << endl;
    cout << "3. View Info" << endl
    cin >> choice;
    if(choice == "1")
    {
        cout << "Enter the amount you want to deposit" << endl;
        cin >> amount;
        cCustomer->cDeposit(amount);
    }
    else if(choice == "2")
    {
        cout << "Enter the amount you want to withdraw" << endl;
        cin >> amount;
        cCustomer->cWithdraw(amount);
    }
    else if(choice == "3")
    {
        cCustomer->cPrint();
    }
}