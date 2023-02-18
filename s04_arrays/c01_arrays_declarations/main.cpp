#include<iostream>
using namespace std;

int main()
{
    int A[6] = {2,4,6,8,10,12};

    for(int i=0; i < 6; i++){
        cout<< A[i] << endl;
    }

    cout<< endl;
    int B[] = {2,4,6,8,10,12};

    for(int i=0; i<6; i++){
        cout<< B[i] << endl;
    }

    cout<< endl;
    int C[] = {2,4,6,8,10};

    for(int x:C){
        cout<< x << endl;
    }

    cout<< endl;
    int D[6] = {2,4,6};

    for(int x:D){
        cout<< x << endl;
    }

    cout<< endl;
    float E[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};

    for(auto x:E){
        cout<< x << endl;
    }

    cout<< endl;
    char F[] = {'A', 66, 'C', 68};

    for(auto x:F){
        cout<< x << endl;
    }

    cout<< endl;
    char G[] = {'A', 66, 'C', 68};

    for(int x:F){
        cout<< x << endl;
    }

    return 0;
}