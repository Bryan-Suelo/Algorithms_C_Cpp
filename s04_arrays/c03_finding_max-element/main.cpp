#include<iostream>
using namespace std;

int main()
{
    int max, num;
    
    cout << "Enter numbers: " << endl;
    cin >> num;
    int A[num];
    
    cout << "Enter elements: " << endl;
    for(int i = 0; i < num; i++){
        cin >> A[i];
    }

    max = A[0];
    for(int i=1; i < num; i++){
        if(A[i] > max){
            max = A[i];
        }
    }

    cout << "Maximum value: " << max << endl;
    return 0;
}