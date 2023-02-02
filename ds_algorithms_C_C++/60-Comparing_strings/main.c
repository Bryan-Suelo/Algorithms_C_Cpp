#include <stdio.h>
#include <stdlib.h>

void ComparingStrings(char A[], char B[])
{
    int i,j;
    for(i=0,j=0; A[i]!='\0' && B[j]!='\0'; i++, j++)
    {
        if(A[i] != B[j])
        {
            break;
        }
    }
    if(A[i] == B[j])
    {
        printf("Equal... \r\n");
    }
    else if(A[i] <= B[j])
    {
        printf("Smaller... \r\n");
    }
    else
    {
        printf("Greater... \r\n");
    }
}

int main()
{
    char A[] = "Painter";
    char B[] = "Painting";
    ComparingStrings(A,B);
    return 0;
}
