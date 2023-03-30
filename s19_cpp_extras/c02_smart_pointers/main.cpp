#include<iostream>
#include<memory>
using namespace std;

class Rectangle {
    private:
        int length;
        int breadth;
    public:
        Rectangle(int l, int b) {
            length = l;
            breadth = b;
        }
        int area() {
            return length*breadth;
        }
        int perimeter() {
            return 2 * (length + breadth);
        }
};

int main() {
    unique_ptr<Rectangle> ptr(new Rectangle(10,5));
    cout << ptr->area() << endl;

    unique_ptr<Rectangle> ptr2;
    ptr2 = move(ptr);

    cout << ptr2->area() << endl;
    /* cout << ptr->area(); 
        Segmentation fault error 
        ptr is now  NULL
    */

    shared_ptr<Rectangle> pptr(new Rectangle(8,5));
    cout << "Results ptr: " << endl;
    cout << pptr->area() << endl;
    cout << pptr->perimeter() << endl;

    /* No Segmentation fault with this smart pointer, both are pointing to same object  */
    cout << "Shared pointers:" << endl;
    shared_ptr<Rectangle> pptr2;
    pptr2 = pptr;
    cout << pptr2->area() << endl;
    cout << pptr->area() << endl;

}