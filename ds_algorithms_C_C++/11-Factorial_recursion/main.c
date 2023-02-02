#include <stdio.h>
#include <stdlib.h>

int iterative_fact(int n)
{
        int f = 1;
        int i;
        for(i=1; i<= n; i++)
        {
            f = f*i;
        }
        return f;
}

int recursive_fact(int n)
{
        if(n == 0)
        {
            return 1;
        }
        else
        {
            return(recursive_fact(n-1)*n);
        }
}

int main()
{
    int r;
    //r = iterative_fact(5);
    r = recursive_fact(5);
    printf("%d\n",r);
    return 0;
}
