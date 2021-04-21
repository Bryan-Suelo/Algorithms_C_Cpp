#include <stdio.h>
#include <stdlib.h>

void ReverseString(char A[], char B[])
{
    int i,j;
    for(i = 0; A[i]!='\0'; i++)
    {
    }
    i = i-1;
    for(j=0; i>=0; i--, j++)
    {
        B[j] = A[i];
    }
    B[j] = '\0';
    printf("Reverse string: %s\r\n",B);
}

void ReverseSame(char A[])
{
    char temp;
    int i,j;
    for(j=0; A[j]!='\0'; j++)
    {
    }

    j= j-1;
    for(i=0; j>i; i++, j--)
    {
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    printf("Reverse string: %s\r\n", A);
}

int main()
{
    char A[] = "python";
    printf("String to reverse: %s\r\n",A);
    char B[sizeof(A)];
    ReverseString(A,B);
    ReverseSame(A);
    return 0;
}
