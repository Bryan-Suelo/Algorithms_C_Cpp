#include <stdio.h>
#include <stdlib.h>

struct array
{
    int A[10];
    int size;
    int length;
};

void FindPair(struct array arr)
{
    for(int i=0; i<arr.length; i++)
    {
        for(int j=i+1; j<arr.length; j++)
        {
            if(arr.A[i]+arr.A[j] == arr.length)
            {
                printf("%d + %d = %d\r\n",arr.A[i], arr.A[j], arr.length);
            }
        }
    }
}

int Max(struct array arr)
{
    int max = arr.A[0];
    for(int i=1; i<arr.length; i++)
    {
        if(arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
}

void HashFindPair(struct array arr)
{
    int max = Max(arr);
    struct array *temparr = (struct array *)malloc(sizeof(struct array));

    for(int i=0; i<max; i++)
    {
        temparr->A[i] = 0;
    }
    for(int i=0; i<arr.length; i++)
    {
        if(temparr->A[arr.length - arr.A[i]] != 0)
        {
            printf("%d + %d = %d\r\n", arr.A[i], arr.length-arr.A[i], arr.length);
        }
        temparr->A[arr.A[i]]++;
    }
    temparr->length = max;
    temparr->size = max-1;
}

int main()
{
    struct array arr = {{6,3,8,10,16,7,5,2,9,14},5,10};
    FindPair(arr);
    //struct array *temparr;
    HashFindPair(arr);
    return 0;
}
