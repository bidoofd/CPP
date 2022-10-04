#ifndef MEDHISTORY_H
#define MEDHISTORY_H
#include <string>
using namespace std;

class Account
{
    private:
        int aAmount;
        string aType;
        string aDate;
        int cAccID;
        int accNum = 0;
    public:
        Account(int vAmount, string vType, string vDate, int vAccID);
        int aGetAmount();
        string aGetType();
        void incAcc();
};

#endif