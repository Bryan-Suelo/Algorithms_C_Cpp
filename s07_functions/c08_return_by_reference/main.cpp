#include<iostream>
using namespace std;

int & func(int &x)
{
    cout << x << endl;
    cout << &x << endl;
    return x;
}

int main()
{
    int a=10;
    func(a);
    cout << &a << endl;
    cout << a << endl;
    cout << endl;

    func(a) = 25;
    cout << a << endl;
    return 0;
}