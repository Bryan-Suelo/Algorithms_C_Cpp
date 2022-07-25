#include <stdio.h>
#include <stdlib.h>

void Swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Bubble(int arr[], int n){
    int flag;
    for(int i=0; i<n-1; i++){
            flag = 0;
        for(int j=0; j<n-i-1; j++){
               if(arr[j] > arr[j+1]){
                    Swap(&arr[j], &arr[j+1]);
                    flag = 1;
               }
        }
        if(flag == 0){
            break;
        }
    }
}

int main(){
    int Arr[] = {3,7,9,10,6,5,12,4,11,2};
    int size = sizeof(Arr)/sizeof(int);

    Bubble(Arr, size);
    for(int i=0; i < size; i++){
        printf("%d ", Arr[i]);
    }
    return 0;
}
