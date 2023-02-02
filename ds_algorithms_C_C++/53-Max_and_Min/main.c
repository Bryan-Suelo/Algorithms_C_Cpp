#include <stdio.h>
#include <stdlib.h>

struct array
{
    int A[10];
    int size;
    int lenght;
};

void Display(struct array arr)
{
    for(int i=0; i<arr.lenght; i++)
    {
        printf("%d ",arr.A[i]);
    }
}

void findMinMax(struct array arr)
{
    int min,max;
    min = arr.A[0];
    //printf("%d ",min);
    max = arr.A[0];
    //printf("%d ",max);

    for(int i=1; i<arr.lenght; i++)
    {
        if(arr.A[i] < min)
        {
            min = arr.A[i];
        }
        else if(arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    printf("Min: %d Max: %d",min,max);
}

int main()
{
    struct array arr={{5,8,3,9,6,2,10,7,-1,4},5,10};
    //Display(arr);
    findMinMax(arr);
    return 0;
}
