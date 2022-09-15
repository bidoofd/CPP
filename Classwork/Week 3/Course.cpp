#include <iostream>
#include "Course.h"

using namespace std;

Course::Course()
{

}

void Course::setCourseID(string sID)
{
    courseID = sID;
}

void Course::setCourseDesc(string sDesc)
{
    courseDesc = sDesc;
}

string Course::getCourseID()
{
    return courseID;
}

string Course::getCourseDesc()
{
    return courseDesc;
}