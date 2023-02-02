#include <stdio.h>
#include <stdlib.h>

int findMax(int A[], int n){
    int max = -1;

    for(int i=0; i<n; i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    return max;
}

void countSort(int A[], int n){
    int max = findMax(A, n);
    int *C;
    C = (int *)malloc(sizeof(int)*max+1);

    for(int i=0; i<max+1; i++){
        C[i] = 0;
    }
    for(int i=0; i<n; i++){
        C[A[i]]++;
    }
    int j = 0;
    int i = 0;
    while(i < max+1){
        if(C[i] > 0){
            A[j++] = i;
            C[i]--;
        }
        else{
            i++;
        }
    }
}

int main()
{
    int A[] = {11,13,7,12,16,9,24,5,10,3};
    int sizeA = sizeof(A)/sizeof(int);

    countSort(A, sizeA);

    for(int i=0; i<sizeA; i++){
        printf("%d ", A[i]);
    }

    return 0;
}
