#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int findNumofPair(int *arr, int n) {
    sort(arr, arr + n);

    int ans = 0;

    for(int i=0; i < n; i++) {
        if (arr[i] <= 0) {
            continue;
        }
        int j = lower_bound(arr, arr + n, -arr[i] + 1) - arr;

        ans += i - j;
    }
    return ans;
}

int main() {
    int a[] = {3, 2,-1};
    int n = sizeof(a) / sizeof(a[0]);

    int ans = findNumofPair(a, n);
    cout << ans << endl; 
}