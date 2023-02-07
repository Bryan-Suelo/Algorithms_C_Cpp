#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str = "Parangaricutirimicuaro";
    int count = 0;

    for(int i=0; str[i] != '\0'; i++){
        count++;
    }

    cout << count << endl;

    count=0;
    string::iterator it;

    for(it= str.begin(); it != str.end(); it++){
        count++;
    }

    cout << count << endl;
    
    return 0;
}