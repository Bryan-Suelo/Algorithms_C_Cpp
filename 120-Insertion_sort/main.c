#include <stdio.h>
#include <stdlib.h>

void Insertion(int arr[], int size){
    int temp;
    int j;

    for(int i=1; i<size; i++){
            j = i-1;
            temp = arr[i];

            while(j>-1 && arr[j]>temp){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = temp;
    }
}

int main()
{
    int A[] = {11,13,7,2,6,9,4,5,10,3};
    int size = sizeof(A)/sizeof(int);

    Insertion(A, size);

    for(int i=0; i<size; i++){
        printf("%d ", A[i]);
    }
    printf("\r\n");

    return 0;
}
