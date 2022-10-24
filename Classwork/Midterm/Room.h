#ifndef ROOM_H
#define ROOM_H
#include <string>

using namespace std;

class Room
{
    private:
        string roomName;
        string spaceAreaName;

    public:
        Room(string n, string a)
        string getRoomName();
        string getSpaceAreaName();
}

#endif