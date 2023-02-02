#include<iostream>
using namespace std;

int main()
{
    char s[100];
    char r[100];

    cout << "Enter your name: ";
    cin.get(s, 100);
    cout << "Welcome " << s << endl;

    cin.ignore(); 
    
    cout << "Enter a new name: ";
    cin.get(r, 100);
    cout << "Welcome " << r << endl;

    return 0;
}