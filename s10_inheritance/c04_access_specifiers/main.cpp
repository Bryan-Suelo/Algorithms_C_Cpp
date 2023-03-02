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

        Base(int a1, int b1, int c1){
            a = a1;
            b = b1;
            c = c1;
        }

        void valBase(){
            cout << a << endl;
            cout << b << endl;
            cout << c << endl; 
        }
};

class Derived: public Base
{
    public:
        void funDerived(){
            cout << b << endl;
            cout << c << endl;
        }
};

int main()
{
    Base x(10,20,30);
    cout << x.c << endl;

    x.valBase();
}