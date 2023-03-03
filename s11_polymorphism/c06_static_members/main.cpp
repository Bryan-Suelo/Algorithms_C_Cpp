#include<iostream>
using namespace std;

class Base
{
    public:
        int a;
        static int count;
        
        Base() {
            a = 10;
            count++;
        }

        static int getCount() {
            return count;
        }
};

int Base::count = 0;

int main()
{
    Base t1;
    cout << t1.count << endl;

    Base t2;
    //cout << t2.count << endl;
    cout << Base::count << endl;

    Base t3;
    cout << t3.getCount() << endl;
}