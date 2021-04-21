#include <stdio.h>
#include <stdlib.h>

void simpleComparing(char A[], int size)
{
    int i,j;
    int count = 1;

    for(i=0; A[i]!='\0'; i++)
    {
        if(A[i] != -1)
        {
            for(j=i+1; j<size-1; j++)
            {
                if(A[i] == A[j])
                {
                    count++;
                    A[j] = -1;
                }
            }
        }
        if(count>1)
        {
            printf("%c appears %d times\r\n",A[i],count);
            count = 1;
        }
    }
}

void comparingHashTable(char A[])
{
    char H[26];
    //printf("%d\r\n",sizeof(H));
    int i;

    for(i=0;i<sizeof(H);i++)
    {
        H[i]=0;
    }
    //H = (int  *)malloc(sizeof(char));
    for(i=0; A[i]!='\0'; i++)
    {
        H[A[i]-97]++;
        //printf("%d\r\n",H[A[i]-97]);
    }
     for(i=0; i<26; i++)
     {
         if(H[i]>1)
         {
             printf("%c repeats %d times\r\n",i+97, H[i]);
         }
     }
}

int main()
{
    char A[] = "finding";
    //printf("%d",sizeof(A));
    //simpleComparing(A, sizeof(A));
    comparingHashTable(A);
    return 0;
}
