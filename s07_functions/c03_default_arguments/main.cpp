#include<iostream>
using namespace std;

int add(int x, int y, int z=0)
{
    return x+y+z;
}

int main()
{
    cout << add(2,5) << endl;
    cout << add(2,5,0) << endl;
    cout << add(2,4,6) << endl;
    return 0;
}