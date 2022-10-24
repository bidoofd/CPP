#ifndef TOWNHOUSE_H
#define TOWNHOUSE_H
#include <string>
#include "House.h"
#include "Room.h"

using namespace std;

class Condo : public Townhouse
{
    private:
        string backyard;
        Room *bRoom;
    
    public:
        TownHouse(string b)
        string getBackywardName();
        string getRoomName();
        string getSpaceAreaName();
}

#endif