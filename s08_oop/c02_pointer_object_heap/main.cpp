#include<iostream>
using namespace std;

class Rectangle
{
    public:
        int length;
        int breadth;
    
        int area(){
            return length * breadth;
        }

        int perimeter(){
            return 2 * (length + breadth);
        }
};

int main()
{
    Rectangle r;
    Rectangle *ptr;

    ptr = &r;

    r.length = 10;
    ptr->breadth = 5;

    cout << ptr->area() << endl;
    cout << ptr->perimeter() << endl;

    cout << r.area() << endl;
    cout << r.perimeter() << endl;

    return 0;
}