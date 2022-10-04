#ifndef MEDHISTORY_H
#define MEDHISTORY_H
#include <string>
using namespace std;

class MedHistory
{
    private:
        int apptNum = 0;
        string reason;
        string date;
    public:
        MedHistory(string vReason, string vDate);
        string getReason();
        string getDate();
        int getApptNum();
        void incApptNum();
};

#endif