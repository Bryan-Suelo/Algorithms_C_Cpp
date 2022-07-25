#include <stdio.h>
#include <stdlib.h>

void Insert(int arr[], int nelement){
    int i = nelement;
    int temp = arr[nelement];

    while(i>1 && temp>arr[i/2]){
        arr[i] = arr[i/2];
        i = i/2;
    }
    arr[i] = temp;
}

int Delete(int arr[], int n){
    int del = arr[1];
    arr[1] = arr[n];
    arr[n] = del;
    int i = 1;
    int j = 2*i;

    while(j > n-1){
        if(arr[j+1] > arr[j]){
            j = j+1;
        }
        if(arr[j] > arr[i]){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i = j;
            j = 2*j;
        }
        else{
            break;
        }
    }
    return del;
}

int main()
{
    int A[] = {0,10,20,30,25,5,40,35};

    for(int i=2; i<sizeof(A)/sizeof(int); i++){
        Insert(A, i);
    }

    printf("Deleted element %d\r\n", Delete(A, 7));

    for(int i=1; i<sizeof(A)/sizeof(int); i++){
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
