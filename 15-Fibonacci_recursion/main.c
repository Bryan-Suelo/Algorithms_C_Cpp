#include <stdio.h>
#include <stdlib.h>

int iterative_fib(int n)
{
    int t0 = 0, t1 = 1, s = 0, i;

    if (n <= 1)
    {
        return n;
    }
    else
    {
        for (i=2; i<=n; i++)
        {
            s=t0 + t1;
            t0 = t1;
            t1 = s;
        }
    }
    return s;
}

int recursive_fib(int n)
{
    if(n <= 1)
    {
        return n;
    }
    else
    {
        return (recursive_fib(n-2)+recursive_fib(n-1));
    }
}

int main()
{
    printf("%d \n", recursive_fib(10));
    //printf("%d \n", iterative_fib(10));
    return 0;
}
