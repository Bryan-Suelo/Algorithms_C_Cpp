#include<iostream>
using namespace std;

int main()
{
    int x=10;
    int y=5;
    int z;

    try{
        if(y == 0){
            throw 1;
        }
        z = x/y;
        cout << z << endl;
    }
    catch(int e){
        cout << "Division by zero " << e << endl;
    }
    return 0;
}