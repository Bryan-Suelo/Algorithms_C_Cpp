#include<iostream>

using namespace std;

int main()
{
    int x;

    cout<< "Enter desired number: " <<endl;
    cin>> x;

    switch (x)
    {
        case 1:
            cout<< "Number 1" <<endl;
            break;

        case 2:
            cout<< "Number 2" <<endl;
            break;

        case 3:
            cout<< "Number 3" <<endl;
                        
        default:
            cout<< "Number not covered" <<endl;
            break;
    }
    return 0;
}