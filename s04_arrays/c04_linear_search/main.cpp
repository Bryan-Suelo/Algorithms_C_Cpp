#include<iostream>
using namespace std;

int main()
{
    int key;
    int A[5];
    int sizeArray = sizeof(A) / sizeof(int);

    cout << "Enter elements:" << endl;

    for(int i=0; i < sizeArray; i++){
        cin>> A[i];
    }

    cout << "Enter key value" << endl;
    cin >> key;

    for(int i=0; i < sizeArray; i++){
        if(A[i] == key){
            cout << "Key found at " << i << endl;
            return 0;
        }
    }

    cout << "Not found" << endl;
    return 0;
}