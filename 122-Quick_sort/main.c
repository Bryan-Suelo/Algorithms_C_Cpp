#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int A[], int low, int high){
    int pivot = A[low];
    int i = low;
    int j = high;

    do{
        do{i++;}while(A[i] <= pivot);
        do{j--;} while(A[j] > pivot);

        if(A[i] < A[j]){
            swap(&A[i], &A[j]);
        }
    }while(i < j);

    swap(&A[low], &A[j]);
    return j;
}

int Quick_sort(int A[], int low, int high){
    int j;
    if(low < high){
        j = Partition(A, low, high);
        Quick_sort(A, low, j);
        Quick_sort(A, j+1, high);
    }
}

int main()
{
    int A[] = {11,13,7,12,16,9,24,5,10,3};
    int sizeA = sizeof(A)/sizeof(int);

    Quick_sort(A, 0, sizeA);

    for(int i=0; i<sizeA; i++){
        printf("%d ", A[i]);
    }
    printf("\r\n");

    return 0;
}
