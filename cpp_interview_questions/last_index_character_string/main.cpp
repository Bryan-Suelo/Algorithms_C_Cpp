#include<iostream>
using namespace std;

int findLastindex(string &str, char x) {
    int index = -1;
    for(int i=0; i < str.length(); i++) {
        if(str[i] == x) {
            index = i;
        }
    }
    return index;
}

int main() {
    string str = "Header";

    char x = 'e';

    int index = findLastindex(str, x);
    if (index == -1) {
        cout << "character not found" << endl;
    }
    else {
        cout << "Last index is: " << index << endl;
    }
    return 0;
}