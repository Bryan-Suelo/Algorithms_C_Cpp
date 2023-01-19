#include <iostream>

using namespace std;

//enum day {mon, tue, wed, thu, fri, sat, sun};
enum day {mon=1, tue, wed, thu, fri, sat, sun};

int main() {
    day d;
    d = sun;

    cout<<d<<endl;
    cout <<mon<< endl;
    cout <<tue<< endl;
    cout <<wed<< endl;
    cout <<thu<< endl;
    cout <<fri<< endl;
    cout <<sat<< endl;
    cout <<sun<< endl;

    return 0;
}

/*
enum
    - Always start from zero
    - We can change the value of each element (mon = 1)
    - Next number has following value (tue = 2)
*/
