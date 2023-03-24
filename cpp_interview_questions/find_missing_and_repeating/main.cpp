#include<iostream>
using namespace std;

void printTwoElements(int arr[], int n) {
    int lastDuplicate = 0;

    for(int i=0; i<n; i++) {
        if(arr[i] == arr[i+1] && arr[i] != lastDuplicate) {
            lastDuplicate = arr[i];
        }
    }
    cout << "The repeating number is " << lastDuplicate<< endl;

    int temp[n] = {0};

    cout << "The missing number is "<< endl;
    for(int i=0; i<n; i++){
        temp[arr[i]]++;
    }
    for(int i=1; i < n; i++) {
        if(temp[i] == 0){
            cout << i << ' ';
        }
    }
    cout << endl;

}
int main() {
    int arr[] = {4, 3, 6, 2, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    printTwoElements(arr, n);
}