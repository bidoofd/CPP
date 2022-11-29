#include <iostream>
#include "TvShow.h"

using namespace std;
// must initialize the data members only once 

string TvShow::actor2 ="Homer Simpson";
int    TvShow::numShows = 0;


int main() {
	
	// Step 1) Create an instance of TvShow called simp (pass in the string "The Simpsons")

	TvShow simp = TvShow("The Simpsons");

	// Step 2) Write code to display the number of shows were instantiated

	cout << simp.numberOfShows() << endl;

	// Step 3) Would the code inside the numberOfShows method still be correct 
	//         if numberOfShows were non-static? If not, why? 

	// Yes, because it is a variable inside the normal class.

	// Step 4) Suppose the code inside the numberOfShows method is replaced with 
	//         the following line: return y;  Is this legal? If not, why?

	// It does not work because it is a non static variable.

	// Step 5) Write code that will print the data member actor2. 
	//         Do this without instantiating any objects.

	cout << TvShow::showActor2() << endl;

	// Step 6) Write code to return (actor2), you may need to add a new method in (.h & .cpp)

	cout << simp.showActor2() << endl;

	// Step 7) Write code to return (showName), you may need to add a new method in (.h & .cpp)

	cout << simp.showShowName() << endl;
	
	system("pause");
	
	return 0;
}
