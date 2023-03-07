#include<iostream>
using namespace std;

class Outer
{
    public:
        int a=10;
        static int b;

        void func() {
            i.show();
        }

        class Inner 
        {
            public:
                int x=25;
                void show() {
                    cout << b << endl;
                }
        };
        Inner i;
};

int Outer::b = 25;

int main()
{
    Outer::Inner i;
    i.show();
}