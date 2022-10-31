#include <iostream>
using namespace std;


void Factorial(int N)
{
// implement the Factorial method that calculate factorial number
// you need to throw exception for the following cases
	
	// 1. throw out_of_range exception if N is negative
	// 2. throw domain_error exception if N is zero
	// 3. throw length_error exception if N is > 10
	int sum = 1;

	if(N < 0)
	{
		throw out_of_range("Error: out of range.\n");
	}
	else if(N == 0)
	{
		throw domain_error("Error: domain error.\n");
	}
	else if(N > 10)
	{
		throw length_error("Error: length error.\n");
	}

	for(int a = 1; a <= N; ++a)
	{
		sum *= a;
	}

	cout << sum << endl;
}

int main () {
   

   int num;

   cout << "Enter a number between 1-10:" << endl;
   cin >> num;

   try
    {
        cout << "The factorial for " << num << " is " << endl;
		Factorial(num);
    }
    catch (out_of_range& e)
    {
        cerr << "Exception occured: out of range." << endl << e.what();
    }
	catch (domain_error& e)
	{
		cerr << "Exception occured: domain error." << endl << e.what();
	}
	catch (length_error& e)
	{
		cerr << "Exception occured: length error." << endl << e.what();
	}
}