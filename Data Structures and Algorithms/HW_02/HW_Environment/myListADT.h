#ifndef MYLISTADT_H
#define MYLISTADT_H
#include <string>

using namespace std;

class myListADT
{
    private:
        string name;
        int pointer = 0;
        int length = 0;
        int *array = new int[length];
    public:
        myListADT(string name, int size);
        int isEmpty();
        int size();
        int at(int i);
        int set(int i, int o);
        int insert(int i, int o, ofstream& file);
        int erase(int i, ofstream& file);
        void printList(ofstream& file);

        void writeOutput(ofstream& file, string line);
};

#endif