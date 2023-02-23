#include<iostream>
using namespace std;

class Base
{
    public:
        Base(){
            cout << "Non-Param base" << endl;
        }
        Base(int x){
            cout << "Param of base " << x << endl;
        }
};

class Derived: public Base
{
    public:
        Derived(){
            cout << "Non-Param Derived" <<  endl;
        }
        Derived(int y){
            cout << "Param of derived" << endl;
        }
        Derived(int x, int y): Base(x){
            cout << "Param of derived " << y << endl;
        }
};

int main()
{
    Derived d;
    Derived d0(5);
    Derived d1(10,5);

}