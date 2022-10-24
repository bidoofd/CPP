#ifndef FOLDER_H
#define FOLDER_H
#include "TextFile.h"
#include "User.h"
#include <string>
using namespace std;

class Folder : public User
{
    private:
        //Folder has a name and amount of items it can hold
        //Amount variables explained before respectively
        //Text file pointer
        string name;
        int sAmount;
        int fAmount;
        TextFile *txtFile;
    public:
        //Creates default folder constructor
        //Functions of folder can store files and other folders
        Folder(string n, int sA, int fA);
        void storeFile();
        void storeFolder();
};

#endif