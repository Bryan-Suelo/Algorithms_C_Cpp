#include<iostream>
using namespace std;

void perfect_number(int n)
{
    int sum=0;

    for(int i = 1; i <= n; i++){
        if(n%i == 0){
            sum += i;
        }
    }

    cout << "Enter perfect number: " << sum << endl << endl;

    if(2*n == sum){
        cout << "Perfect" << endl;
    }
    else{
        cout << "Not pefect" << endl;
    }
}

int main()
{
    int n;

    cout << "Enter number:" << endl;
    cin >> n;

    perfect_number(n);

    return 0;
}