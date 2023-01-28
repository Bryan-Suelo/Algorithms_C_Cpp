#include<iostream>
using namespace std;

int main()
{
    int A[10] = {6,8,13,17,20,22,25,28,30,35};
    int l = 0;
    int h = (sizeof(A)/sizeof(int)) - 1;
    int key, mid;

    cout << "Enter key element: ";
    cin >> key;

    while(l <= h){
        mid = (l+h)/2;
        cout << mid << endl;

        if(key == A[mid]){
            cout << "Key element found" << endl;
            return 0;
        }
        else if(key < A[mid]){
            h = mid -1;
        }
        else{
            l = mid + 1;
        }
    }

    cout << "Element not found" << endl;
    return 0;
}