#include <stdio.h>
#include <stdlib.h>

void Merge(int A[], int low, int mid, int high){
    int i = low;
    int j = mid+1;
    int k = low;
    int B[high];

    while(i<=mid && j<=high){
        if(A[i] < A[j]){
            B[k++] = A[i++];
        }
        else{
            B[k++] = A[j++];
        }
    }

    for(; i<=mid; i++){
        B[k++] = A[i];
    }
    for(; j<=high; j++){
        B[k++] = A[j];
    }

    for(i=low; i<=high; i++){
        A[i] = B[i];
    }
}

void IMergeSort(int A[], int n){
    int low, mid, high, p, i;

    for(p=2; p<=n; p*=2){
            for(i=0; i+p-1<n; i+=p){
                low = i;
                high = (i+p)-1;
                mid = (low+high)/2;
                Merge(A, low, mid, high);
            }
    }
    if(p/2 < n){
        Merge(A, 0, p/2-1, n);
    }
}

void RMergeSort(int A[], int low, int high){
    if(low < high){
        int mid = (low + high)/2;
        RMergeSort(A, low, mid);
        RMergeSort(A, mid+1, high);
        Merge(A, low, mid, high);
    }
}

int main()
{
    int A[] = {11,13,7,12,16,9,24,5,10,3};
    int n = sizeof(A)/sizeof(int);

    //IMergeSort(A, 10);
    RMergeSort(A, 0, n-1);

    for(int i=0; i<n; i++){
        printf("%d ", A[i]);
    }
    return 0;
}
