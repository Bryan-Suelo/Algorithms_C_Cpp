#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

int Display(struct Array arr)
{
    int i;
    for(i = 0; i <arr.length; i++)
    {
        printf("%d  ",arr.A[i]);
    }
    printf("\r\n");
    return 0;
}

void Left_shift(struct Array *arr)
{
    int temp;
    int i;
    temp = arr->A[0];

    for(i = 0; i < arr->length; i++)
    {
        arr->A[i] = arr->A[i+1];
    }
    arr->A[arr->length - 1] = temp;
}

void Rigth_shift(struct Array *arr)
{
    int temp;
    int i;
    temp = arr->A[arr->length - 1];

    for(i = arr->length; i > 0; i--)
    {
        arr->A[i] = arr->A[i -1];
    }
    arr->A[0] = temp;
}
int main()
{
    struct Array arr = {{1,2,3,4,5}, 10, 5};

    Left_shift(&arr);
    Display(arr);
    Rigth_shift(&arr);
    Display(arr);
    return 0;
}
