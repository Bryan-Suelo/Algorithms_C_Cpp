#include<iostream>
using namespace std;

class Test
{
    private:
        int a;
        int *p;
    public:
        Test(int x){
            a = x;
            p = new int[a];
        }

        Test(Test &t){
            a = t.a;
            p = new int [a];
        }
};

int main()
{
    Test t(5);
    Test t1(t);
    return 0;
}