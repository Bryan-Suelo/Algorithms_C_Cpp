#include <stdio.h>
#include <stdlib.h>

int recursive_pow(int m, int n)
{
        if(n == 0)
        {
            return 1;
        }
        else
        {
            return(recursive_pow(m,n-1)*m);
        }
}

int power(int m, int n)
{
        if(n == 0)
        {
            return 1;
        }
        if((n%2) == 0)
        {
            return(power(m*m,n/2));
        }
        else
        {
            return(m*power(m*m,(n-1)/2));
        }
}

int main()
{
    int r;
    r = recursive_pow(2,9);
    r = power(2,9);
    printf("%d\n",r);
    return 0;
}
