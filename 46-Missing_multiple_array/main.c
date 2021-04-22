#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[15];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    for(i=0; i<arr.length; i++)
    {
        printf("%d ",arr.A[i]);
    }
    printf("\r\n");
}

int Min(struct Array arr)
{
    int min = arr.A[0];
    int i;
    for(i=1; i<arr.length; i++)
    {
        if(arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }
    return min;
}

void Missing_element(struct Array arr, int min)
{
    int diff;
    /* Zero is the first index in array */
    diff = min - 0;
    for(int i=0; i<arr.length; i++)
    {
        if(arr.A[i]-i != diff)
        {
            while(diff < arr.A[i]-i)
            {
                printf("%d\n", i+diff);
                diff++;
            }
        }
    }
}

int main()
{
    struct Array arr1 = {{6,7,8,9,11,12,15,16,17,18,19},16,11};
    int min = Min(arr1);
    Missing_element(arr1,min);
    return 0;
}
