#ifndef MYLISTADT_H
#define MYLISTADT_H
#include <string>

using namespace std;

class myListADT
{
    private:
        string name;
        int array[256];
    public:
        int isEmpty();
        int size();
        int at(int i);
        int set(int i, int o);
        int insert(int i, int o);
        int erase(int i);
};

#endif