#include<iostream>
using namespace std;

template<typename T>
void fun(T func) {
    func();
}

int main() {
    [](){cout << "Hello" << endl;}();

    [] (int x, int y) {cout << "Sum result: " << x+y << endl;}(5,8);
    cout << "Sum result: " <<([] (int x, int y) {return x+y;}(5,8)) << endl << endl;

    int a = [] (int x, int y) -> int{return x*y;}(1,30);
    cout << "Multiply result: " << a << endl << endl;

    int x = 10;
    auto f = [&x] () {cout << x++ << endl;};
    f();
    f();

    fun(f);
}