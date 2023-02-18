#include<iostream>
using namespace std;

void prime_number(int n)
{
    int count=0;

    for(int i=1; i <= n; i++){
        if(n % i == 0){
            count++;
        }
    }

    if(count == 2){
        cout << "Prime" << endl;
    }
    else{
        cout << "Not Prime" << endl;
    }
}

int main()
{
    int n;

    cout << "Enter n: " << endl;
    cin >> n;

    prime_number(n);

    return 0;
}