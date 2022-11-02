#ifndef CALLER_H
#define CALLER_H
#include "Callee.h"

#include <string>
#include <iostream>

using namespace std;

class Caller
{
    private:
        //variables for header
        string name
        int phoneNumber;
        string contact;
        Callee *aCallee;
    public:
        //get contact function
        string getContact(string cont);
        //dials the number
        int dialNumber(int phoneNum);
        //Uses callee to make their phone ring/hangup
        void phoneRing(Callee *aCallee);
        void hangup(Callee *aCallee)
        //void functions for sound/text for rejection/acception of call
        void dialTone();
        void stopBusy();
        void stopDial();
};

#endif