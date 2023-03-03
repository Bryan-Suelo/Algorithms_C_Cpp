#include<iostream>
using namespace std;

class Student
{
    public:
        int roll;
        string name;
        static int addNo;

        Student(string n) {
            addNo++;
            name = n;
            roll = addNo;
        }

        void Display() {
            cout << "Name: " << name << endl << "Roll: " << roll << endl;
        }
};

int Student::addNo = 0;

int main()
{
    Student s1("John");
    Student s2("Bryan");

    s1.Display();
    s2.Display();

    cout << "Number Admission: " << Student::addNo << endl;
    return 0;
}