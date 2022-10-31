#include <iostream>
using namespace std;

double division(int a, int b)
{
    if(b == 0)
    {
        throw runtime_error("Error: Attempted to divide by zero\n");
    }

    return (a/b);
}

int main()
{
    int x = 4;
    int y = 2;
    double z;
    try
    {
        z = division(x,y);
        cout << " the result of the division is " << z << endl;
    }
    catch (runtime_error& e)
    {
        cerr << "Exception occured" << endl << e.what();
    }
}