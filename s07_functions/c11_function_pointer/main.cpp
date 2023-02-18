#include<iostream>
using namespace std;

int max(int x, int y)
{
    return x>y?x:y;
}

int min(int x, int y)
{
    return x<y?x:y;
}

int main()
{
    int (*fp)(int, int);

    fp=max;
    int res = (*fp)(10,5);
    cout << res << endl;

    fp=min;
    res = (*fp)(10,5);
    cout << res << endl;

    return 0;
}