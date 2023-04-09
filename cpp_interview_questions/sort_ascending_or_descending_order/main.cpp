#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void twoWaySort(int arr[], int n) {
    int l = 0;
    int r = n - 1;
    int k = 0;

    while(l < 0) {
        while(arr[l] % 2 != 0) {
            l++;
            k++;
        }
        while(arr[r] % 2 == 0 && l < r) {
            r--;
        }
        if(l < r) {
            swap(arr[l], arr[r]);
        }
    }

    sort(arr, arr + k, greater<int>());
    sort(arr+k, arr +n);
}

int main() {
    int arr[] = {1, 3, 2, 7, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    twoWaySort(arr,n);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}