#include<iostream>
using namespace std;

class Demo
{
    public:
        int x = 15;
        int y = 25;

        void Display() const {
            //x++;
            cout << x << " " << y << endl;
        }
};

void fun(const int &a, int b) {
    cout << a << " " << b << endl;
    //a++;
}

int main() {

    int const x = 10;
    //x = 30; Cannot modify value
    cout << x << endl;

    // Const Pointers
    int y = 10;
    const int *ptr = &y;
    cout << y << " " << *ptr << endl;

    int z = 10;
    const int * const ptrr = &z;
    //++*ptrr; cannnot modify this value, integer constant
    //ptrr = &y; NOt allowed, cannot modify const pointer value
    cout << x << " " << *ptr << endl;

    Demo d;
    d.Display();

    int a = 1;
    int b = 2;
    fun(a,b);
    cout << a << " " << b << endl;
}