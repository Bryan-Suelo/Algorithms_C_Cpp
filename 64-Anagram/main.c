#include <stdio.h>
#include <stdlib.h>

void anagram(char *A, char *B)
{
    int i;
    int H[26]={0};

    for(i=0; A[i]!='\0'; i++)
    {
        H[A[i]-97]+=1;
    }
    for(i=0; B[i]!='\0'; i++)
    {
        H[B[i]-97]-=1;
        if(H[B[i]-97] < 0)
        {
            printf("Not an anagram\r\n");
            break;
        }
    }
    if(B[i] == '\0')
    {
        printf("It's an anagram \r\n");
    }
}

int main()
{
    char A[] = "decimal";
    char B[] = "medical";
    anagram(A, B);
    return 0;
}