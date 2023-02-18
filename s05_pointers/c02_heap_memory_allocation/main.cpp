#include<iostream>
using namespace std;

int main()
{
    /* Create Array in heap */
    int *p = new int[5];
    p[0] = 12;
    p[1] = 13;

    for(int i=0; i<5; i++){
        cout << p[i] << endl;
    }

    delete []p;
    p = nullptr;

    /*Adjust size of Array*/
    int size;
    cout << "Enter desired size:" << endl;
    cin >> size;
    int *ptr = new int[size];
    cout << sizeof(ptr) << endl;

    delete []ptr;
    ptr = nullptr;

    cout << "Enter desired size:" << endl;
    cin >> size;
    ptr = new int[size];
    cout << sizeof(ptr) << endl;

    return 0;
}