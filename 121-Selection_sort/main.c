#include <stdio.h>
#include <stdlib.h>

void Swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void InsertionSort(int A[], int n){
    int j,k;
    for(int i=0; i<n; i++){
        for(j=k=i; j<n; j++){
            if(A[j] < A[k]){
                k=j;
            }
        }
        Swap(&A[i], &A[k]);
    }
}

int main()
{
    int A[] = {11,13,7,12,16,9,24,5,10,3};
    int size = sizeof(A)/sizeof(int);

    InsertionSort(A, size);

    for(int i=0; i<size; i++){
        printf("%d ", A[i]);
    }
    printf("\r\n");

    return 0;
}
