#include <stdio.h>
#include <stdlib.h>

struct array
{
    int A[10];
    int size;
    int length;
};

void Display(struct array arr)
{
        int i;
        for(i=0; i < arr.length; i++)
        {
            printf("%d  ", arr.A[i]);
        }
}

int Get(struct array arr, int index)
{
    if(index >= 0 && index < arr.length)
    {
        return arr.A[index];
    }
    else
    {
        return -1;
    }
}

void Set(struct array *arr, int index, int value)
{
    if(index >= 0 && index < arr->length)
    {
        arr->A[index] = value;
    }
}

int Max(struct array arr)
{
    int max = arr.A[0];
    int i;
    for(i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
}

int Min(struct array arr)
{
    int min = arr.A[0];
    int i;
    for(i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }
    return min;
}

int iterative_Sum(struct array arr)
{
    int i;
    int total = 0;
    for(i =0; i < arr.length; i++)
    {
        total = total + arr.A[i];
    }
    return total;
}

int recursive_Sum(struct array arr, int n)
{
    if (n < 0)
    {
        return 0;
    }
    else
    {
        return recursive_Sum(arr, n-1) + arr.A[n];
    }
}

float Avg(struct array arr)
{
    //return (float)iterative_Sum(arr) / arr.length;
    return (float) recursive_Sum(arr,arr.length) / arr.length;
}

int main()
{
    struct array arr = {{10,20,3,4,5},10,5};

   printf("%d \n",Get(arr, 2));

    Set(&arr,3,10);
    Display(arr);
    printf("\r\n");

    printf("%d \n", Max(arr));

    printf("%d \n", Min(arr));

    printf("%d \n", iterative_Sum(arr));

    printf("%d \n", recursive_Sum(arr, arr.length));

    printf("%f \n", Avg(arr));

    return 0;
}
