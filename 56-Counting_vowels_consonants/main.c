#include <stdio.h>
#include <stdlib.h>

void Counting(char A[])
{
   int i;
   int vcount = 0;
   int ccount = 0;

    for(i=0; A[i]!='\0'; i++)
    {
        if((A[i]=='a') || (A[i]=='e') || (A[i]=='i') || (A[i]=='o') || (A[i]=='u') ||
            (A[i]=='A') || (A[i]=='E') || (A[i]=='I') || (A[i]=='O') || (A[i]=='U'))
        {
            vcount++;
        }
        else if((A[i]>=65 && A[i]<=90) || (A[i]>=97 && A[i]<=122))
        {
            ccount++;
        }
    }
    printf("%d vowels; %d consonants\r\n", vcount, ccount);
}

int main()
{
    char A[] = "How are you";
    Counting(A);
    return 0;
}
