#include<iostream>
using namespace std;

// First approach
void rotate(int arr[], int n) {
    int x = arr[n - 1], i;
    for (i = n - 1; i > 0; i--){
        arr[i] = arr[i - 1];
    }
    arr[0] = x;
}

void display(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

// Second approach
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp; 
}

void rotate_2(int arr[], int n) {
    int i = 0;
    int j = n - 1;
    while(i != j) {
        swap(&arr[i], &arr[j]);
        i++;
    }

}
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is" << endl;
    display(arr, n);

    //rotate(arr,n);
    rotate_2(arr,n);

    cout << "Rotated array is " << endl;
    display(arr, n);
}