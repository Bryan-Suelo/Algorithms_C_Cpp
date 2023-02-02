#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    /* Find Substring */
    char s1[20] = "Programming";
    char s2[10] = "gram";

    if((strstr(s1,s2)) != NULL){
        cout << strstr(s1,s2) << endl;
    }
    else{
        cout << "Not found" << endl;
    }

    /* Find occurrence  of given character */
    char s3[20] = "Exercise";
    
    cout << strchr(s3, 'i') << endl;

    cout << strrchr(s3, 'r') << endl;

    return 0;
}