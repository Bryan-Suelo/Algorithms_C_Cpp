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
        printf("%d ", arr.A[i]);
    }
}

void swap(int *x, int *y)
{
        int temp;
        temp = *x;
        *x = *y;
        *y = temp;
}

int transposition(struct Array *arr, int key)
{
        int i;
        for (i = 0; i < arr->length; i++)
        {
            if (key == arr->A[i])
            {
                swap(&arr->A[i], &arr->A[i-1]);
                return i;
            }
        }
        return -1;
}

int main()
{
    struct Array arr = {{1,2,3,4,5}, 10, 5};

    printf("%d \r\n", transposition(&arr, 3));
    Display(arr);

    return 0;
}
