#include<iostream>
using namespace std;

class Parent{
    private: int a;
    protected: int b;
    public:
        int c;
        Parent(){
            a = 5;
            b = 10;
            c = 15;
        }
        Parent(int a1, int b1, int c1){
            a = a1;
            b = b1;
            c = c1;
        }
        void funParent(){
             a = 10;
             b = 5;
             c = 15;
        }
        void Display(){
            cout << a << endl;
            cout << b << endl;
            cout << c << endl;
        }
};

class Child: protected Parent{
    
    public:
        void funChild(){
            // Private element from Parent cannot be accessed if it is public
            // Private element from Parent cannot be accessed if it is protected
            //a = 10; 
            b = 20;
            c = 30;
    }
};

class Grandchild: protected Child{
    public:
        void funGchild(){
            // Private element from Child cannot be accessed if it is public
            //a = 2;  
            b = 4;
            c = 6;
        }
};

int main(){
    Parent pt(2,4,6);
    pt.Display();

    Child ch;
    // Non accessible when Child: protected Parent
    //ch.Display();

    Grandchild gch;
    // Non accessible when Child: protected Parent
    //gch.Display();
    gch.funGchild();
}