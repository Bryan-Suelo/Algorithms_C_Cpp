#include<iostream>
using namespace std;

class Rectangle
{
    private:
        int length;
        int breadth;
    public:
        Rectangle();
        Rectangle(int l, int b);
        Rectangle(Rectangle &r);
        void setLength(int l);
        void setBreadth(int b);
        int getLenth() {return length;}
        int getBreadth() {return breadth;}
        int area();
        int perimeter();
        bool isSquare();
        ~Rectangle();
};

int main()
{
    Rectangle r1(10,10);
    cout << "Area " << r1.area() << endl;
    cout << "Perimeter " << r1.perimeter() << endl;

    Rectangle r2(r1);
    if(r2.isSquare()){
        cout << "Is a square" << endl;
    }
    else{
        cout << "Not a square" << endl;
    }

    Rectangle r3(4,8);
    cout << "Area " << r3.area() << endl;
    cout << "Perimeter " << r3.perimeter() << endl;

}

Rectangle::Rectangle(){
    length=1;
    breadth=1;
}

Rectangle::Rectangle(int l, int b){
    length = l;
    breadth = b;
}

Rectangle::Rectangle(Rectangle &r){
    length = r.length;
    breadth = r.breadth;
}

void Rectangle::setLength(int l){
    length = l;
}

void Rectangle::setBreadth(int b){
    breadth = b;
}

int Rectangle::area(){
    return length * breadth;
}

int Rectangle::perimeter(){
    return 2 * (length + breadth);
}

bool Rectangle::isSquare(){
    return length == breadth;
}

Rectangle::~Rectangle(){
    cout << "Object deleted" << endl;
}