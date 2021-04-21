#include <stdio.h>
#include <stdlib.h>

void perm(char s[], int k)
{
    static int A[10] = {0};
    static char Res[10];
    int i;

    if(s[k] == '\0')
    {
        Res[k] = '\0';
        printf("%s\r\n", Res);
    }
    else
    {
        for(i=0; s[i]!='\0'; i++)
        {
            if(A[i] == 0)
            {
                Res[k] = s[i];
                A[i] = 1;
                perm(s,k+1);
                A[i] = 0;
            }
        }
    }
}

int swap(char l, char h)
{
    int temp;
    temp = l;
    l = h;
    h = temp;
    return l,h;
}

void perms(char s[], int l, int h)
{
    int i;
    if(l == h)
    {
        printf("%s\r\n",s);
    }
    else
    {
        for(i=l; i<=h; i++)
        {
            swap(s[l],s[i]);
            perms(s,l+1,h);
            swap(s[l],s[i]);
        }
    }
}

int main()
{
    char s[] = "ABC";
    perm(s,0);
    printf("\r\n");
    perms(s,0,2);
     return 0;
}
