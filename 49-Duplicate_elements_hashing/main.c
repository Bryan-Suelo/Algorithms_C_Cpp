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
    for(int i =0; i<arr.length; i++)
    {
        printf("%d ",arr.A[i]);
    }
}

int Max(struct Array arr)
{
    int max,i;
    max = arr.A[0];
    for(i=1; i<arr.length; i++)
    {
        if(arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
}

int Min(struct Array arr)
{
    int min,i;
    min = arr.A[0];
    for(i=1; i<arr.length; i++)
    {
        if(arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }
    return min;
}

void FindDuplicates(struct Array arr)
{
    int i, max/*, min*/;
    max = Max(arr);
    //printf("Max is %d\n",max);
    //min = Min(arr);
    //printf("Min is %d\n",min);

    struct Array *arrtemp = (struct Array *)malloc(sizeof(struct Array));

    for(i=0; i<max; i++)
    {
         arrtemp->A[i] = 0;
         //printf("%d ",arrtemp->A[i]);
    }
    //printf("\r\n");
    Display(*arrtemp);
   for(i=0; i<arr.length; i++)
    {
        arrtemp->A[arr.A[i]]++;
    }
    for(i=0; i<max; i++)
    {
        if(arrtemp->A[i] > 1)
        {
            printf("%d is appearing %d times\r\n",i,arrtemp->A[i]);
        }
    }
    arrtemp->length = max;
    arrtemp->size = max-1;
}

int main()
{
    struct Array arr = {{3,6,8,8,10,12,15,15,15,20},10,10};
    struct Array *arrtemp;
    FindDuplicates(arr);
    Display(*arrtemp);
    return 0;
}
