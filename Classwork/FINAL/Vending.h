#ifndef VENDING_H
#define VENDING_H
#include <string>
using namespace std;

class Vending
{
    private:
        int chocolate = 3;
        double cPrice = 1.95;
        int chips = 1;
        double chipsPrice = 1.25;
        int apple = 2;
        double aPrice = 1.50;
        string choice;
        string name;
        double sum = 0;
        double price = 0;
    public:
        Vending(string name);
        void selectItem();
        double addCoins();
        void displayCoins();
        void printItem();
        void printChange();
        bool available();
};

#endif