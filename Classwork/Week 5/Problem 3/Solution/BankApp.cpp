#include "Customer.h"
#include "Saving.h"
#include "Checking.h"
#include <iostream>
using namespace std;
 
int main()
{ 
// Hint: work on each step independently, compile and fix errors if any
//       before jumping to the next one

// step 1) create a customer object here

	Customer c1 = Customer("Jason", "1234");

// step 2) create a saving object here with balance 0, must pass the customer object
//         you may need to see Doctor application solution 

	Saving s1 = Saving("Saving", "0", "01/01/2000", 0, &c1);

// step 3) print the customer ID and PIN info using saving object

	s1.getCustomerID();
	s1.getCustomerID()->getPIN();

// step 4) make a deposit of 100

	s1.deposit(100);

// step 5) print the balance
	s1.getBalance();

// step 6) make a withdraw of 60 
	s1.withdraw(60);

// step 7) print the balance
	s1.getBalance();

// step 8) make a withdraw of 100
	s1.withdraw(100);

// step 9) print the balance
	s1.getBalance();

// step 10) print the saving information by calling each method in the class
	s1.getType();
	s1.getNumber();
	s1.getOpenDate();
	s1.getBalance();
	s1.getCustomerID()->getID();

// step 11) create another customer object here

	Customer c2 = Customer("Bob", "0000");

// step 12) create a checking account

	Checking ch1 = Checking("Checking", "0", "01/01/2000", 0, &c2);

// step 13) make a series of deposit and withdraw transactions

	ch1.deposit(200);
	ch1.getBalance();
	ch1.withdraw(50);
	ch1.getBalance();
	
	return 0;
}