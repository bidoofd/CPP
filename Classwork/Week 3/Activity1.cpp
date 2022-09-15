#include <iostream>
#include "Course.h"

using namespace std;

int main()
{
    Course CPP;
    CPP.setCourseID("ENGR3430");
    CPP.setCourseDesc("Adv ENGR App Programming");
    cout << "Course " << CPP.getCourseID() << " has the description: " << CPP.getCourseDesc() << endl;

    return 0;
}