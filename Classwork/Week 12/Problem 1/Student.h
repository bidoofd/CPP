#include <string>
using namespace std;

class Student {  
	private:
		string id;
		string name;
		static int numOfStudents;
	public:
		Student();  
		void setID(string stdID);
		string getID();
		void setName(string stdName);
		string getName();
		~Student();
		static int studentCount();
};
