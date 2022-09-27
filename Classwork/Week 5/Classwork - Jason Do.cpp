#include <iostream>
using namespace std;
 

// Sets up Doctor class
class Doctor
{
    public:
        Doctor()
        {
        
        }
        string name;
        int age;
        string date;  
        int apptNum; 


// Functions of doctor
    string setName()
    {
        cout << "Enter name of patient: " << endl;
        cin >> name;
        return name;
    }

    int setAge()
    {
        cout << "Enter age of patient: " << endl;
        cin >> age;
        return age;
    }

    string setDate()
    {
        cout << "Enter the date of the appointment: " << endl;
        cin >> date;
        return date;
    }

};

// Patient class

class Patient{
    public:
        string name;
        int age;
        string date;
        int aptNum;
 
    Patient()
    {

    }
 
    Patient(string n, int a, string d, int x) {
        name = n;
        age = a;
        date = d;
        aptNum = x;
    }
 
    void printDetails() {
        cout << "Appt # " << aptNum << " " << name << " - " << age << " - " << date << endl;
    }

    int getPatAge()
    {
        return age;
    }
};

int getAge(Patient pat)
    {
        int age = pat.getPatAge();
        return age;
    }
 
int main() {
    //sets up an empty array of entries and variables
    Patient patients[10];
    for(int a = 0; a < 10; a++)
    {
        patients[a] = Patient("", -1, "", -1);
    }
    int choice, choice2, age, count;
    string name, date;
// Menu to ask whether or not user is patient or doctor
    while(choice != 3)
    {
    cout << "Enter the number that applies to you" << endl;
    cout << "1. Doctor" << endl;
    cout << "2. Patient" << endl;
    cout << "3. Exit" << endl;
    cin >> choice;

    if(choice == 1)
    {
        //Create doctor object to use functions
        Doctor d1;
        while(choice != 4)
        {
            cout << "What would you like to do?" << endl;
            cout << "1. Enter new patient" << endl;
            cout << "2. Clear Patient History" << endl;
            cout << "3. View Patient History" << endl;
            cout << "4. Exit" << endl;
            cin >> choice2;
            if(choice2== 1)
            {
                //Uses doctor functions to set patients information and add it to patient list
                name = d1.setName();
                age = d1.setAge();
                date = d1.setDate();
                patients[count] = Patient(name, age, date, count);
                cout << "Your appointment number is: " << count << endl;;
                count++;
            }
            else if(choice2 == 2)
            {
                //Clears patient list history
                for(int a = 0; a < 10; a++)
                {
                    patients[a] = Patient("", -1, "", -1);
                }
            }
            else if (choice2 == 3)
            {
                //prints out patient list history
                for(int i=0; i < 5; i++) 
                {
                    patients[i].printDetails();
                }
            }
            else if(choice2 == 4)
            {
                break;
            }
            else
            {
                cout << "Not a valid choice" << endl;
            }
        }
    }
    else if (choice == 2)
    {
        //Patient can either view their visit or just exit
        cout << "What would you like to do?" << endl;
        cout << "1. View Visit" << endl;
        cout << "2. Exit" << endl;
        cin >> choice2;
        if(choice2 == 1)
        {
            //Has to enter appt # to view their information
            int choice3;
            cout << "Enter your appointment #: " << endl;
            cin >> choice3;
            for(int a = 0; a < 10; a++)
            {
                if(getAge(patients[a]) == choice3)
                {
                    patients[choice3].printDetails();
                }
            }
        }
    }
    }
}