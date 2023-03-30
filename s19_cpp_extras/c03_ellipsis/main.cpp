#include<iostream>
#include<stdarg.h>
using namespace std;

int sum(int n, ...) {
    va_list list;
    va_start(list, n);

    int x;
    int s = 0;
    for(int i=0; i < n; i++) {
        x = va_arg(list, int);
        s += x;
    }

    return s;
}

int main() {
    cout << sum(3, 1,2,0) << endl;
    cout << sum(5, 2,3,6,8,5) << endl;
}

