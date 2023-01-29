#ifndef MYLISTADT_H
#define MYLISTADT_H
#include <string>

using namespace std;

class myListADT
{
    private:
        string name;
        int length = 0;
        int *array = new int[length];
    public:
        myListADT(string name, int size);
        int isEmpty();
        int size();
        int at(int i);
        int set(int i, int o);
        int insert(int i, int o);
        int erase(int i);
};

#endif