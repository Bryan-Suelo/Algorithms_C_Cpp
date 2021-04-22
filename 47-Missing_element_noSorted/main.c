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
    for(int i=0; i<arr.length; i++)
    {
        printf("%d ",arr.A[i]);
    }
}

int Min(struct Array arr)
{
    int min = arr.A[0];
    for(int i=0; i<arr.length; i++)
    {
        if(arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }
    return min;
}

int Max(struct Array arr)
{
    int max=arr.A[0];
    for(int i = 1; i<arr.length; i++)
    {
        if(arr.A[i]>max)
        {
            max = arr.A[i];
        }
    }
    return max;
}

void Element(struct Array arr)
{
    int i, min, max;
    min = Min(arr);
    max = Max(arr);
    /*printf("%d ",max);
    printf("%d\r\n",min);*/

    struct Array *arrtemp = (struct Array *)malloc(sizeof(struct Array));

    for(i=0; i<max; i++)
    {
        arrtemp->A[i]=0;
    }
    for(i=0; i<arr.length; i++)
    {
        arrtemp->A[arr.A[i]]++;
    }
    for(i=min; i<max; i++)
    {
        if(arrtemp->A[i]==0)
        {
            printf("%d ",i);
        }
    }
    arrtemp->length = max;
    arrtemp->size = max-1;
}

int main()
{
    struct Array arr={{3,7,4,9,12,6,1,11,2,10},10,10};
    struct Array *arrtemp;
    Element(arr);

    return 0;
}
