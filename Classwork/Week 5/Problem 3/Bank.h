#ifndef BANK_H
#define BANK_H
#include "Customer.h"
#include <string>
#include <iostream>

using namespace std;

class Bank
{
    private:
        string bName;
        Customer *cCustomer;
    public:
        Bank(string bName);
        void offerService();
};

#endif