#include <stdio.h>
#include <stdlib.h>

struct Array
{
        int A[20];
        //int size;
        int lenght;
};

void Display(struct Array arr)
{
    int i;
    for(i = 0; i < arr.lenght; i++)
    {
        printf("%d ",arr.A[i]);
    }
}

int main()
{
    struct Array arr = {{1,2,3},5};
    Display(arr);
    return 0;
}
