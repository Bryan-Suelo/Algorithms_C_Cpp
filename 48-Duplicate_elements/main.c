#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void FindDuplicate(struct Array arr)
{
    int lastDuplicate = 0;
    for(int i =0; i< arr.length; i++)
    {
        if((arr.A[i]== arr.A[i+1]) && (arr.A[i]!=lastDuplicate))
        {
            printf("%d\n", arr.A[i]);
            lastDuplicate = arr.A[i];
        }
    }
}

void CountDuplicate(struct Array arr)
{
    int j;
    for(int i=0; i<arr.length; i++)
    {
        if(arr.A[i] == arr.A[i+1])
        {
            j= i+1;
            while(arr.A[j] == arr.A[i])
            {
                j++;
            }
            printf("%d is appearing %d times\r\n", arr.A[i], j-i);
            i = j-1;
        }
    }
}

int main()
{
    struct Array arr ={{3,6,8,8,10,12,15,15,15,20}, 8, 10};
    FindDuplicate(arr);
    CountDuplicate(arr);
    return 0;
}
