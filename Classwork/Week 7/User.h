#ifndef USER_H
#define USER_H
#include "Folder.h"

#include <string>

using namespace std;

class User
{
    private:
        //Variables of string for the name of user
        //Folder class as pointer to folder
        //Variable storeAmount of amount of items a single user can hold
        //Variable folderAmount of amount of folders wanting to be created
        string name;
        Folder *vFolder;
        int storeAmount;
        int folderAmount;
    public:
        //Default constructor of user
        User(string n);
        //Functions to create folders, save or print files
        void createFolder(Folder *vFolder, int sA, int fA);
        void saveFile();
        void printFile();
    
};

#endif