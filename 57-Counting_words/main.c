#include <stdio.h>
#include <stdlib.h>

void Countingwords(char A[])
{
    int i;
    int word = 1;
    for(i=0; A[i]!='\0'; i++)
    {
        if(A[i]==' ' && A[i-1]!=' ')
        {
            word++;
        }
    }
    printf("%d words \r\n", word);
}

int main()
{

    char A[] = "How are   u";
    Countingwords(A);
    return 0;
}
