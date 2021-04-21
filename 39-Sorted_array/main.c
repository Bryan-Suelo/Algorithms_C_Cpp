#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int Size;
    int Length;
};

int Display(struct Array arr)
{
    int i;
    for (i=0; i < arr.Length; i++)
    {
        printf("%d ",arr.A[i]);
    }
    printf("\r\n");
    return 0;
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void InsertSort(struct Array *arr, int x)
{
        int i = arr->Length-1;
        /* Validate if lenght is equal to size */
        if (arr->Length == arr->Size)
        {
            return;
        }
        while (i >= 0 && arr->A[i]>x)
        {
            arr->A[i+1] = arr->A[i];
            i--;
        }
        arr->A[i+1] = x;
        arr->Length++;
}

int isSorted(struct Array arr)
{
        for(int i = 0; i < arr.Length-1;i++)
        {
            if(arr.A[i] > arr.A[i+1])
            {
                /* This return means false */
                return 0;
            }
        }
        /* This return means true */
        return 1;
}

void Rearrange(struct Array *arr)
{
    int i = 0;
    int j = arr->Length-1;
    while(i < j)
    {
        while(arr->A[i]<0)
        {
            i++;
        }
        while(arr->A[j]>=0)
        {
            j--;
        }
        if(i < j)
        {
            swap(&arr->A[i], &arr->A[j]);
        }
    }
}

int main()
{
    struct Array arr = {{2,-3,15,10,-5,-12}, 10 ,6};

    //InsertSort(&arr, 12);
    //printf("%d \r\n", isSorted(arr));
    Rearrange(&arr);

    Display(arr);

    return 0;
}
