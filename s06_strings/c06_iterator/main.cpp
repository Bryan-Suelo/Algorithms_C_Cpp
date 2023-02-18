#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str = "Welcome";
    
    string::iterator it;

    for(it= str.begin(); it != str.end(); it++){
        cout << *it;
    }

    cout << endl;

    for(int i=0; str[i] != '\0'; i++){
        cout << str[i];
    }
    cout << endl;

    string::reverse_iterator rit;

    for(rit = str.rbegin(); rit != str.rend(); rit++){
        cout << *rit;
    }

    return 0;
}