#include <string>
using namespace std;

class Course
{
    private:
        string courseID;
        string courseDesc;
    public:
        Course();
        void setCourseID(string sID);
        string getCourseID();
        void setCourseDesc(string sDesc);
        string getCourseDesc();
};