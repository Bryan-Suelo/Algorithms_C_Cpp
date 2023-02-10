#include<iostream>
using namespace std;

template <class T>
T maxim(T x, T y)
{
    return x>y?x:y;
}

int main()
{
    cout << maxim(12,15) << endl;
    cout << maxim(3.6f, 4.1f) << endl;
    return 0;
}