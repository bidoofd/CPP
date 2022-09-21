#include "Faculty.h"
#include <string>
#include <iostream>
using namespace std;

Faculty::Faculty(int o, string r, string n, string a)
{
    offNum = o;
    rank = r;
    name = n;
    address = a;
}

int Faculty::getOffNum()
{
    return offNum;
}

string Faculty::getName()
{
	return name;
}

string Faculty::getAddress()
{
	return address;
}

string Faculty::getRank()
{
    return rank;
}
