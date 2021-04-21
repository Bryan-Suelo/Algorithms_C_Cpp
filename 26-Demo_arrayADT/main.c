#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr)
{
        int i;
        printf("\r\nElements are\r\n");
        for(i=0 ; i < arr.length; i++)
        {
            printf("%d\n", arr.A[i]);
        }
}

int main()
{
    struct Array arr;
    int n;
    int i;

    printf("Enter size of an array ... \n");
    scanf("%d", &arr.size);
    arr.A = (int *) malloc(arr.size * sizeof(int));
    printf("\n");

    printf("Enter number of members ... \n");
    scanf("%d", &n);
    printf("\n");

    printf("Enter all the elements ... \n");
    for(i=0 ; i<n ; i++)
    {
        scanf("%d", &arr.A[i]);
    }
    arr.length = n;

    Display(arr);
    return 0;
}
