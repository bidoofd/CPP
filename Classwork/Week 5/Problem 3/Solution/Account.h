#ifndef ACCOUNT_H // condition the definition to prevent multiple inclusion
#define ACCOUNT_H
#include <string>
#include "Customer.h"
using namespace std;

class Account
{
	protected :	
		string number; 
		string openDate;
		double balance;
		Customer *customerID;   // implement the association r/s
		
	public: 	
   // make the Account class abstract, the implementation will be in derived classes
		virtual string getNumber()=0; 									
		string getOpenDate();
		double getBalance();
		void deposit(double amount);
		void withdraw(double amount);
		Customer *getCustomerID();
};

#endif