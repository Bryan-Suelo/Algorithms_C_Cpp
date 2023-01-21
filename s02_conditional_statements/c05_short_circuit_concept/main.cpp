#include<iostream>

using namespace std;

int main()
{
    int a=10, b=5, i=5;

    if(a>b && ++i<b){
        cout<< i <<endl;
    }

    /* 
        a<b is false, it means ++i<b will not be evaluated
        Some compilers do not print the value
    */
    i=5;
    if(a<b && ++i<b){
        cout<< i <<endl;
    }

    /*
        While using OR conditional, even when first comparison is False,
        compiler will evaluate the second condition
    */
    i=5;
    if(a<b || ++i<=b){
        cout<< i <<endl;
    }

    i=5;
    if(a>b || ++i<=b){
        cout<< i <<endl;
    }

    return 0;
}