#include<iostream>
using namespace std;

int main()
{
    int x = 10;
    int &y = x;

    cout << x << endl;
    cout << y << endl;

    x++;
    y++;

    cout << x << endl;
    cout << y << endl;

    cout << &x << " " << &y << endl;
    return 0;
}