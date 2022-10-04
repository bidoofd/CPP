#include "MedHistory.h"
#include <iostream>
#include <string>
using namespace std;


MedHistory::MedHistory(string vReason, string vDate)
{
    reason = vReason;
    date = vDate;
}

string MedHistory::getReason()
{
    return reason;
}

int MedHistory::getApptNum()
{
    return apptNum;
}

string MedHistory::getDate()
{
    return date;
}

void MedHistory::incApptNum()
{
    apptNum++;
}