#include<iostream>
using namespace std;

class Base
{
    public:
        void func1() {
            cout << "Base func 1" << endl;
        }
        virtual void func2()=0;
};

class Derived : public Base
{
    public:
        void func2() {
            cout << "Derived func 2" << endl;
        }
};

int main()
{
    Base *b;
    Derived d;
    b = &d;
    b -> func1();
    b -> func2();
}