#include <stdio.h>
#include <stdlib.h>

void bitwiseOp(char A[])
{
    long int H=0, x=0;
    int i,sub;

    for(i=0; A[i]!='\0'; i++)
    {
        x=1;
        sub = A[i]-97;
        x= x<<sub;
        if(x & H > 0)
        {
            printf("%c is duplucated \r\n",A[i]);
        }
        else
        {
            H=1;
            H= x | H;
        }
    }
}

int main()
{
    char A[] = "finding";
    bitwiseOp(A);
    return 0;
}
