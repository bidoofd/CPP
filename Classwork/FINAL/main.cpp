#include "Vending.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int choice = 1;
    Vending v1("Vending Machine");
    while(choice == 1 && v1.available() == true)
    {
        v1.selectItem();
        v1.addCoins();
        v1.printItem();
        cout << "Would you like to buy another product? (1 YES, 0 NO)" << endl;
        cin >> choice;
    }
    if(v1.available() == false)
    {
        cout << "One of the items in the vending machine is unavailable. You cannot purchase any further" << endl;
    }
}