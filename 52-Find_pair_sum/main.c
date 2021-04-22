#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void findPair(struct Array arr)
{
    int i,j;
    for(i=0, j=arr.length-1; i<j;)
    {
        if(arr.A[i] + arr.A[j] == arr.length)
        {
            printf("%d + %d = %d\r\n", arr.A[i], arr.A[j], arr.length);
            i++;
            j--;
        }
        else if(arr.A[i] + arr.A[j] < arr.length)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
}

int main()
{
    struct Array arr = {{1,3,4,5,6,8,9,10,12,14},5,10};
    findPair(arr);
    return 0;
}
