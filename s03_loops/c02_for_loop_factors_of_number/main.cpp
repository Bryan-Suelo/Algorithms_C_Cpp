#include<iostream>
using namespace std;

void factors(int n)
{
    for(int i = 1; i <= n; i++){
        if( n % i == 0){
            cout << i << endl;
        }
    }
}

int main()
{
    int n;

    cout << "Enter n: " << endl;
    cin >> n;

    factors(n);
    
    return 0;
}