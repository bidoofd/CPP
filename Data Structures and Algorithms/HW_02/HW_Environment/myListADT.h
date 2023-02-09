#ifndef MYLISTADT_H
#define MYLISTADT_H
#include <string>

using namespace std;

class myListADT
{
    private:
        // Variables
        //  - name: name for object
        //  - pointer: size of current array
        //  - length: size of actual array
        //  - *array: dynamically creates array based on length

        string name;
        int pointer = 0;
        int length = 0;
        int *array = new int[length];
    public:
        // Methods
        //  - myListADT(): creates the myListADT object
        //  - isEmpty(): checks to see if array in object is empty
        //  - size(): returns size of the current array (not max size)
        //  - at(): returns the value of the inputted index
        //  - set(): changes the value at the inputted index with the inputted object
        //  - insert(): inserts a value at the inputted index with the inputted object
        //      - it also shifts the elements to keep order
        //  - erase(): erases the value at the inputted index and shifts elements to keep order
        //  - printList(): prints the values inside the array of the object
        //  - writeOutput(): writes to file for tracing

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