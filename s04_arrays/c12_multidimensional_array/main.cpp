#include<iostream>
using namespace std;

int main()
{
    int A[2][3] = {2,4,6,1,3,5};

    for(auto& x:A){
        for(auto& y:x){
            cout << y << " ";
        }
        cout << endl;
    }
}