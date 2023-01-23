#include <iostream>
#include <string>

using namespace std;

int main()
{
    int array[256], size, values;

    cout << "Enter in how many values you want to enter into the array: " << endl;
    cin >> size;
    cout << "Enter in the values: " << endl;
    for(int a = 0; a < size; a++)
    {
        cin >> values;
        array[a] = values;
    }
}