#include <stdio.h>
#include <stdlib.h>

/* First exercise */
/*int f(int n)
{
    static int i = 1;

    if (n>=5)
    {
        return n;
    }
    n = n+i;
    i++;

    return f(n);
}*/

void foo (int n, int sum)
{
    int k = 0, j = 0;
    if (n == 0)
    {
        return;
    }

    k = n % 10;
    j = n/10;
    sum = sum + k;
    foo(j, sum);
    printf("%d \n", k);
}

int main()
{
    /* First exercise */
    //printf("%d\n",f(1));
    /* Second exercise */
    int a = 2048, sum = 0;
    foo (a, sum);
    printf("%d\n", sum);

    return 0;
}
