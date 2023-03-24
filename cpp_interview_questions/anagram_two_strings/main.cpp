#include<iostream>
using namespace std;

bool areAnagram(string str1, string str2) {
    int i;
    int h[20] = {0};

    for(i = 0; str1[i] != '\0'; i++) {
        h[str1[i] - 97]++;
    } 
    for(i = 0; str2[i] != '\0'; i++) {
        h[str1[i] - 97]--;

        if(h[str1[i]-97] < 0) {
            cout << "Not anagram" << endl;
        }
    } 
    if(str2[i] == '\0') {
        cout << "Anagram" << endl;
    }
}
int main() {
    string str1 = "decimal";
    string str2 = "medical";

    if (areAnagram(str1, str2))
        cout << "The two strings are anagram of each other" << endl;
    else
        cout << "The two strings are not anagram of each " << endl;
}