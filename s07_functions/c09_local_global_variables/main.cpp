#include<iostream>
using namespace std;

int g=5;

void func()
{
    int g=10;
    {
        int g=10;
        g++;
        cout << g << endl;
    }
    cout << g << endl;
}

int main()
{
    cout << g << endl;
    func();
    cout << g << endl;
    return 0;
}