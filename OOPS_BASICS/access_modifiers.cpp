#include <iostream>

using namespace std;

class Teacher
{
public:
    string name;
    string dpt;
    string subject;
    double salary;

    void changeDept(string dept)
    {
        dpt = dept;
    }
};

int main()
{
    Teacher t1;
    t1.name = "shivam";
    t1.dpt = "cse";
    t1.subject = "c++";
    t1.salary = 90000.23;
    cout << " name is" << t1.name << " dept is " << t1.dpt << " subject is " << t1.subject << " salary is " << t1.salary << "\n";
    cout << "change dept function..." << endl;
    t1.changeDept("mechanical");
    cout << " name is" << t1.name << " dept is " << t1.dpt << " subject is " << t1.subject << " salary is " << t1.salary << "\n";

    return 0;
}