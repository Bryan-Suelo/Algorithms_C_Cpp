#include <stdio.h>
#include <stdlib.h>

int sum(int n)
{
        return(n*(n+1)/2);
}

int iterative_sum(int n)
{
    int s = 0;
    int i;
    for(i=1;i<=n;i++)
    {
        s=s+i;
    }
    return s;
}

int recursive_sum(int n)
{
    if(n==0)
    {
        return 0;
    }
    else
    {
        return(recursive_sum(n-1)+n);
    }
}

int main()
{
    int a;
    //a = sum(5);
    //a = iterative_sum(5);
    a = recursive_sum(5);
    printf("%d\n",a);
    return 0;
}
