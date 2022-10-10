#ifndef CUSTOMER_H // condition the definition to prevent multiple inclusion
#define CUSTOMER_H
#include <string>
using namespace std;

class Customer
{
	protected :
		string ID; 
		string PIN;
	public: 
	    Customer(string id, string pin);
	    string getID();  // this method should return the ID									
		string getPIN(); // this method should return the PIN
};

#endif