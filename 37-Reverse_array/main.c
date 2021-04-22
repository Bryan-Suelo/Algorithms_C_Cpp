#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    for (i = 0; i < arr.length; i++)
    {
        printf("%d  ", arr.A[i]);
    }
}

void Reverse(struct Array *arr)
{
    int *B;
    int i,j;

    B = (int *)malloc(arr->length * sizeof(int));
    for ( i = arr->length-1, j=0; i >= 0; i--, j++)
    {
        B[j] = arr->A[i];
    }
    for ( i = 0; i < arr->length; i++)
    {
        arr->A[i] = B[i];
    }
}

void Swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void Reverse_fast(struct Array *arr)
{
    int i,j;
    for(i = 0, j = arr->length- 1; i < j; i++, j--)
    {
        Swap(&arr->A[i], &arr->A[j]);
    }
}

int main()
{
    struct Array arr = {{1,2,3,4,5}, 10, 5};
    Reverse(&arr);
    Display(arr);
    Reverse_fast(&arr);
    Display(arr);
    return 0;
}
