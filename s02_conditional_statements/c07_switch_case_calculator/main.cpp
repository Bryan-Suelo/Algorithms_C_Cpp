#include <iostream>
using namespace std;

void calculator(int x, int y, int operation){
    switch (operation)
    {
    case 1:
        cout<< x+y <<endl;
        break;

    case 2:
        cout<< x-y <<endl;
        break;

    case 3:
        cout<< x*y <<endl;
        break;

    case 4:
        cout<< x/y <<endl;
        break;

    default:
        break;
    }
}

int main(){
    int x,y,choice;

    cout<< "Select the operation:" <<endl;
    cout<< "1 -- Add\n" << "2 -- Subtract\n" << "3 -- Multiply\n" <<  "4 -- Divide\n";
    cin>> choice;
    
    cout<< "Enter numbers:" <<endl;
    cin>> x >> y;

    calculator(x,y,choice);

    return 0;
}