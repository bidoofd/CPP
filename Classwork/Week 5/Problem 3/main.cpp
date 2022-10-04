#include "Bank.h"
#include <iostream>
#include <string>
#include <random>

int main()
{
    Bank ban("Bank M");
    Customer list[100];
    string name, choice, date;
    int id;

    cout << "Enter your name: " << endl;
    cin >> name;
    cout << "What type of account do you want to open? (Checking/Saving)" << endl;
    cin >> choice;
    cout << "Enter the date: " << endl;
    cin >> date;

    srand(time(NULL));

    id = rand() % 100 + 1;

    list[0] = Customer(name, id, choice, date);
    ban.offerService();

}
