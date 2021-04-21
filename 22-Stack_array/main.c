#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[5] = {2, 4, 4, 10,6};
    int *p;
    int i;

    for(i=0; i < 5; i++)
    {
            printf("%d \n", A[i]);
    }

    printf("\n");
    p = (int *) malloc(5*sizeof(int));
    p[0] = 3;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 3;

    for(i=0; i < 5; i++)
    {
            printf("%d \n", p[i]);
    }
    return 0;
}
