#ifndef HOUSE_H
#define HOUSE_H
#include <string>

using namespace std;

class House
{
    private:
        string address;

    public:
        virtual string getRoomNum() = 0;
        virtual string getSpaceAreaName() = 0;
}

#endif