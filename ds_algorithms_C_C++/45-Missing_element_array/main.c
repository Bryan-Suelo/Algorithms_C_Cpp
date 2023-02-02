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

int Max(struct Array arr)
{
    int max = arr.A[0];
    int i;
    for(i=1; i<arr.length; i++)
    {
        if(arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
}

void Missing_element(struct Array arr, int max)
{
    int sum = 0;
    int s;
    for(int i=0; i<arr.length; i++)
    {
        sum = sum + arr.A[i];
    }
    //printf("%d\r\n",sum);
    s = (max*(max+1)) / 2;
    //printf("%d\r\n",s);
    printf("Missing number is %d\r\n", s-sum);
}

void Missing_element_2(struct Array arr, int min)
{
    int diff;
    /* Zero is the first index in array */
    diff = min - 0;
    for(int i=0; i<arr.length; i++)
    {
        if(arr.A[i]-i != diff)
        {
            printf("Missing element %d\n", i+diff);
            break;
        }
    }
}

int main()
{
    struct Array arr = {{1,2,3,4,5,6,8,9,10,11,12},16,11};
    int max = Max(arr);
    Missing_element(arr,max);
    struct Array arr1 = {{6,7,8,9,10,11,13,14,15,16,17},16,11};
    int min = Min(arr1);
    Missing_element_2(arr1,min);
    return 0;
}
