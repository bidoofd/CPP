#include "Vending.h"
#include<iostream>
#include <string>

using namespace std;

Vending::Vending(string n)
{
    name = n;
}

void Vending::selectItem()
{
    if(available() == true)
    {
    cout << "What item would you like to buy?" << endl;
    cout << "1. Chocolate: $" << cPrice << "\t Total Remaining: " << chocolate << endl;
    cout << "2. Chips: $" << chipsPrice << "\t Total Remaining: " << chips << endl;
    cout << "3. Apple: $" << aPrice << "\t Total Remaining: " << apple << endl;
    cout << "Please enter in 1, 2, or 3." << endl;
    cin >> choice;
    if(choice.compare("1") == 0 && chocolate != 0)
    {
        chocolate = chocolate - 1;
        choice = "chocolate";
        price = cPrice;
        cout << "You have chosen chocolate." << endl;
        cout << "Please enter in your coins." << endl;
    }
    else if(choice.compare("2") == 0 & chips != 0)
    {
        chips = chips - 1;
        choice = "chips";
        price = chipsPrice;
        cout << "You have chosen chips." << endl;
        cout << "Please enter in your coins." << endl;
    }
    else if(choice.compare("2") == 0 && apple != 0)
    {
        apple = apple - 1;
        choice = "apple";
        price = aPrice;
        cout << "You have chosen apple." << endl;
        cout << "Please enter in your coins." << endl;
    }
    else
    {
        cout << "Not a valid choice." <<endl;
        selectItem();
    }
    }
    else if(available() == false)
    {
        cout << "One of the items is unavailable. You cannot purchase an item." << endl;
    }
}

double Vending::addCoins()
{
    string choice2;
    while(choice2.compare("6"))
    {
        cout << "Enter what coin you want to enter" << endl;
        cout << "1. Penny (0.01)" << endl;
        cout << "2. Nickel (0.05)" << endl;
        cout << "3. Dime (0.10)" << endl;
        cout << "4. Quarter (0.25)" << endl;
        cout << "5. Dollar (1.00)" << endl;
        cout << "6. FINISH ENTERING COINS" << endl;

        displayCoins();

        cin >> choice2;
        if(choice2.compare("1") == 0)
        {
            sum = sum + 0.01;
        }
        else if(choice2.compare("2") == 0)
        {
            sum = sum + 0.05;
        }
        else if(choice2.compare("3") == 0)
        {
            sum = sum + 0.10;
        }
        else if(choice2.compare("4") == 0)
        {
            sum = sum + 0.25;
        }
        else if(choice2.compare("5") == 0)
        {
            sum = sum + 1;
        }
        else if(choice2.compare("6") == 0)
        {
            break;
        }
        else
        {
            cout << "Not a valid choice" << endl;
        }
    }
    return sum;
}

void Vending::displayCoins()
{
    cout << "The amount of coins you entered is: $" << sum << endl;
}

void Vending::printItem()
{
    if(sum < price)
    {
        cout << "You do not have enough money to buy " << choice << "." << endl;
    }
    else if (sum >= price)
    {
        cout << "You have successfully purchased " << choice << "." << endl;
        printChange();
    }
}

void Vending::printChange()
{
    double change = (sum - price);
    cout << "Your change is $" << change << endl;
    sum = 0;
}

bool Vending::available()
{
    if(chocolate != 0 && chips != 0 && apple != 0)
    {
        return true;
    }
}