#include<iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

void isPalindrome(char str[]) {
    int j = strlen(str) - 1;
    int i = 0;
    for(i = 0; j > i; i++, j--) {
        if(str[i] != str[j]) {
            cout << " Not equal" << endl;
            break;
        }
    }
    if(str[i] == str[j]) {
        cout << " Is palindrome" << endl;
    }
}
int main() {
    isPalindrome("abba");
    isPalindrome("abbccbba");
    isPalindrome("geeks");
}