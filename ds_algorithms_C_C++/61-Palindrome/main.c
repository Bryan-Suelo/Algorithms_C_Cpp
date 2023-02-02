#include <stdio.h>
#include <stdlib.h>

void Palindrome(char A[])
{
    int i,j;
    for(j=0; A[j]!='\0';j++)
    {
    }
    j=j-1;
    for(i=0; j>i; i++,j--)
    {
        if(A[i]!=A[j])
        {
            printf("Not equal... \r\n");
            break;
        }
    }
    if(A[i]==A[j])
    {
        printf("It's a palindrome\r\n");
    }
}

void ItsPalindrome(char A[], char B[])
{
    /* Reverse */
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

    /* Compare */
    for(i=0,j=0; A[i]!='\0' && B[j]!='\0'; i++, j++)
    {
        if(A[i] != B[j])
        {
            printf("Not equal... \r\n");
            break;
        }
    }
    if(A[i]==A[j])
    {
        printf("It's a palindrome\r\n");
    }
}

int main()
{
    char A[] = "madam";
    //printf("%d\r\n",sizeof(A));
    //Palindrome(A);
    char B[sizeof(A)];
    //printf("%d\r\n",sizeof(B));
    ItsPalindrome(A,B);
    return 0;
}
