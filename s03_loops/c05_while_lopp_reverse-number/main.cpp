#include<iostream>
using namespace std;

void reverse(int n)
{
    int r, rev=0;

    while(n > 0){
        r = n % 10;
        n = n / 10;
        rev = rev * 10 + r;
    }

    cout << rev << endl;
}

int main()
{
    int n;

    cout << "Enter n:" << endl;
    cin >> n;

    reverse(n);

    return 0;
}