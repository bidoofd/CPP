#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Account.h"
#include <string>
using namespace std;.

class Customer
{
    private:
        string cName;
        int cID;
        int cPin;
        int cAmount;
        Account *aAccount;
        string cAccType;
        string cAccDate;
    public:
        Customer();
        Customer(string n, int i, int p, string d);
        string cGetName();
        int cGetID();
        int cGetPin();
        int cDeposit(int cAmount, string cAccType, string cAccDate);
        int cWithdraw(int cAmount, string cAccType, string cAccDate);
        void cPrint();
        void createCustomer(string cName, int cID, int cPin);
};

#endif
