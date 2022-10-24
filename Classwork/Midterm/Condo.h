#ifndef CONDO_H
#define CONDO_H
#include <string>
#include "House.h"
#include "Room.h"

using namespace std;

class Condo : public Townhouse
{
    private:
        double hoaFee;
        int condoNum;
        Room *aRoom;

    public:
        Condo(double f, int n)
        double getFee();
        int getCondoNum();
        string getRoomNum();
        string getSpaceAreaName();
}

#endif