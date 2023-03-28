#include<iostream>
using namespace std;

bool find_sum_of_two(int arr[], int val, size_t start_index, int n) {
    for(int i = start_index, j = n - 1; i < j; ) {
        int sum = arr[i] + arr[j];
        
        if (sum == val) {
            return true;
        }
        else if(sum < val) {
            ++i;
        }
        else {
            --j;
        }
    }
    return false;    
}

bool find_sum_of_three(int arr[], int required_sum, int n) {
    //sort(arr.begin(), arr.end());

    for (int i=0; i < n-2; ++i) {
        int remaining_sum = required_sum - arr[i];
        if (find_sum_of_two(arr, remaining_sum, i+1, n)) {
            return true;
        }
    }
    return false;
}

int main() {
    int arr[] = {-25, -10, -7, -3, 2, 4, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<"-8: " <<find_sum_of_three(arr, -8, n)<<endl; 
    cout<<"-25: "<<find_sum_of_three(arr, -25, n)<<endl;
    cout<<"0: " <<find_sum_of_three(arr, 0, n)<<endl;
    cout<<"-42: " <<find_sum_of_three(arr, -42, n)<<endl; 
    cout<<"22: " <<find_sum_of_three(arr, 22, n)<<endl; 
    cout<<"-7: " <<find_sum_of_three(arr, -7, n)<<endl;
    cout<<"-3: " <<find_sum_of_three(arr, -3, n)<<endl; 
    cout<<"2: " <<find_sum_of_three(arr, 2, n)<<endl; 
    cout<<"4: " <<find_sum_of_three(arr, 4, n)<<endl; 
    cout<<"8: " <<find_sum_of_three(arr, 8, n)<<endl; 
    cout<<"7: " <<find_sum_of_three(arr, 7, n)<<endl; 
    cout<<"1: " <<find_sum_of_three(arr, 1, n)<<endl;
  
    return 0;
}