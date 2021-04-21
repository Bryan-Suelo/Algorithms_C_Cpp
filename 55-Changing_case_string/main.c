#include <stdio.h>
#include <stdlib.h>

void Uppercase(char A[])
{
    int i;
    for(i=0; A[i]!='\0'; i++)
    {
        A[i]+=32;
    }
    printf("%s\r\n",A);
}

void ChangeCase(char A[])
{
    int i;
    for(i=0; A[i]!='\0'; i++)
    {
        if(A[i]>=65 && A[i]<=90)
        {
            A[i]+= 32;
        }
        else if(A[i]>=97 && A[i]<=122)
        {
            A[i]-=32;
        }
    }
    printf("%s\r\n",A);
}

int main()
{
    char A[] = "WELCOME";
    Uppercase(A);

    char Z[] = "W5lCoMe";
    ChangeCase(Z);
    return 0;
}
