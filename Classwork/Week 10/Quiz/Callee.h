#ifndef CALLEE_H
#define CALLEE_H
#include "Caller.h"

#include <string>
#include <iostream>

using namespace std;

class Callee
{
    private:
        //variables for header
        string name
        int phoneNumber;
        string answer;
        Caller *aCaller;
    public:
        //Callee can answer or reject the call
        string ansORrej(string ans);
        //Hangup function connected to caller
        void hangup(Caller *aCaller);
        //sends busy tone to caller
        void busyTone(Caller *aCaller);
        //void functions for sound/text output for acception or rejection of call
        void stopDial();
        void stopRing();
};

#endif