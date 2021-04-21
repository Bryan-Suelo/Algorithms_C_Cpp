#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[5];
    int i;

    int B[5] = {52, 665, 4, 56, 98};
    int C[10] = {2, 4, 6};
    int D[5] = {0};
    int E[] = {52, 665, 4, 56, 98};

    for(i=0; i < 5; i++)
    {
        printf("%u \n", &A[i]);
    }

    return 0;
}
