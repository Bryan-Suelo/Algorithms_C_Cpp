#include <stdio.h>
#include <stdlib.h>

struct Array
{
        int A[10];
        int size;
        int lenght;
};

void Display(struct Array arr)
{
    int i;
    for(i = 0; i < arr.lenght; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

void Append(struct Array *arr, int x)
{
        if(arr->lenght < arr->size)
        {
            printf("%d \n", x);
            arr->A[arr->lenght++] = x;
        }
}

int main()
{
    struct Array arr = {{1,2,3,4,5},10,5};

    Append(&arr, 10);
    Display(arr);

    return 0;
}
