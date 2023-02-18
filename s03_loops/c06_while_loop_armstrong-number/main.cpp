#include<iostream>
#include<math.h>
using namespace std;

void armstrong_number(int n)
{
    int sum = 0;
    int r;
    int m = n;

    while(n > 0){
        r = n % 10;
        n = n / 10;
        sum = sum + pow(r,3);
    }

    if(sum == m){
        cout << "It's Armstrong" << endl;
    }
    else{
        cout << "Not Armstrong" << endl;
    }
}

int main()
{
    int n;

    cout << "Enter number" << endl;
    cin >> n;

    armstrong_number(n);

    return 0;
}