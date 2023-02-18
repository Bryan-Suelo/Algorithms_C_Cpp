#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char s1[20] = "Good";
    char s2[10] = "Morning";

    cout << "Length of s1: " << strlen(s1) << endl;
    cout << "Length of s2: " << strlen(s2) << endl;

    strcat(s1, s2);
    cout << s1 << endl;

    char s3[20] = "Good"; 
    strncat(s3,s2,3);
    cout << s3 << endl;

    char s4[20] = " ";
    strcpy(s4,s2);
    cout << s4 << endl;

    return 0;
}