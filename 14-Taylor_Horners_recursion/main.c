#include <stdio.h>
#include <stdlib.h>

double recursive_e(int x, int n)
{
    static double s  =1;
    if(n == 0)
    {
        return s;
    }
    else
    {
        s = 1 + x*s/n;
        return recursive_e(x,n-1);
    }
}

double iterative_e(int x, int n)
{
        double s = 1;
        int i;
        double num = 1;
        double den = 1;

        for (i = 1; i <= n; i++)
        {
            num *= x;
            den *= i;
            s+=num/den;
        }
        return s;
}

int main()
{
    printf("%lf\n", recursive_e(2,10));
    printf("%lf\n", iterative_e(1,4));
    return 0;
}
