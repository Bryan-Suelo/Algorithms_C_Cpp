#include<iostream>
using namespace std;

int main()
{
    int A[5] = {2,4,6,8,10};
    int *p=A;

    /* Print array elements */
    cout << *p << endl;
    p++;
    cout << *p << endl;
    p--;
    cout << *p << endl;

    /* Get addresses of elements */
    cout << endl;
    cout << p << endl;
    cout << p+2 << endl;

    /* Print elements */
    cout << endl;
    cout << *p << endl;
    cout << *(p+2) << endl;

    /* Return elements from array */
    cout << endl;
    for(int i=0; i < sizeof(A)/sizeof(int); i++){
        cout << *(A+i) << endl;
    }

    /* Return elements from array */
    cout << endl;
    for(int i=0; i < sizeof(A)/sizeof(int); i++){
        cout << *(p+i) << endl;
    }

    /* Return elements from array */
    cout << endl;
    for(int i=0; i < sizeof(A)/sizeof(int); i++){
        cout << p[i] << endl;
    }    
    /* Return addresses from array */
    cout << endl;
    for(int i=0; i < sizeof(A)/sizeof(int); i++){
        cout << A+i << endl;
    }
    return 0;
}