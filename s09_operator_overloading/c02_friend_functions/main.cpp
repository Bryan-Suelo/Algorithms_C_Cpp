#include<iostream>
using namespace std;

class Complex
{
    private:
        int real;
        int img;
    public:
        Complex(int r=0, int i=0){
            real = r;
            img = i;
        }

        void Display(){
            cout << real << " + i" << img << endl;
        }

        friend Complex operator + (Complex c1, Complex c2);
};

Complex operator + (Complex c1, Complex c2){
    Complex temp;
    temp.real = c1.real + c2.real;
    temp.img = c1.img + c2.img;
    return temp;
}

int main()
{
    Complex c1(2,6);
    Complex c2(7,8);
    Complex c3;

    c3 = c1 + c2;

    c3.Display();

    Complex c4;
    c4 = c3 + c1;
    c4.Display();

    return 0;
}