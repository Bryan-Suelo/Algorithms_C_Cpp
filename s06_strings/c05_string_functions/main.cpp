#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    /* Converting string to number */
    char s1[10] = "235";
    char s2[10] = "23.67";

    long int x = strtol(s1, NULL, 10);
    float y = strtof(s2, NULL);

    cout << x << endl;
    cout << y << endl;

    /* Tokeniser */
    char s3[30] = "x=10;y=20;z=30";
    char *token  = strtok(s3, ";");

    while(token != NULL){
        cout << token << endl;
        token = strtok(NULL, ";");
    }

    return 0;
}