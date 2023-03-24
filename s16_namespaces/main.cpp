#include<iostream>
using namespace std;

namespace First {
    void Fun() {
        cout << "First" << endl;
    }
};

namespace Second {
    void Fun() {
        cout << "Second" << endl;
    }
}

int main() {
    First::Fun();
    Second::Fun();
    
}
