#ifndef SAVING_H   // condition the definition to prevent multiple inclusion
#define SAVING_H

#include "Account.h"
#include <string>
using namespace std;

class Saving : public Account {   // implement the generalization r/s
private:
	string type;
	// inherit the rest of the attributes from Account class
public:
    Saving(string t, string n, string od, double bal, Customer *id); // constructor
	string getType(); 				// this method should return the account type
	string getNumber(); 			// this method should return the account number						
	string getOpenDate();			// this method should return the account open date 
	double getBalance();			// this method should return the account balance  
	void deposit(double amount);	// this method should increment the account balance 
	void withdraw(double amount);	// this method should decrease the account balance 
	Customer *getCustomerID();		// this method should return the customer associate with the account 
};

#endif