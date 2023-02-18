#include<iostream>
using namespace std;

int * array(int size)
{
    int *p = new int[size];
    for(int i=0; i<size; i++){
        p[i] = 5*i;
    }
    return p;
}

int main()
{
    int size=5;
    int *q = array(size);

    for(int i=0; i<size; i++){
        cout << q[i] << endl;
    }
    return 0;
}