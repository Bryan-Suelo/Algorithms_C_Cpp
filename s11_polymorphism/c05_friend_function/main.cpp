#include<iostream>
using namespace std;

class Base
{
    private:
        int a;
    protected:
        int b;
    public:
        int c;
        friend void func();
        friend class Derived;
};

class Derived 
{
    public:
        Base m;
        void fun() {
            m.a = 10;
            m.b = 20;
            m.c = 30;
        }
};

void func() {
    Base m;
    m.a = 10;
    m.b = 20;
    m.c = 30;
}

int main()
{

}