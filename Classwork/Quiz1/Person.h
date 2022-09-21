#ifndef PERSON_H   // condition the definition to prevent multiple inclusion
#define PERSON_H
#include <string>
using namespace std;

class Person
{
    protected:
        string name;
        string address;

    public:
        string getName();
        string getAddress();
};

#endif