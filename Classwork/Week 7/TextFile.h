#ifndef TEXTFILE_H
#define TEXTFILE_H
#include <string>
using namespace std;

class TextFile
{
    private:
        string name;
        string ext;
    public:
        TextFile(string n, string e);
};

#endif