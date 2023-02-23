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
        int getLength(){return length;};
        int getBreadth(){return breadth;};
        void setLength(int l);
        void setBreath(int b);
        int area(){return length * breadth;};
        int perimeter(){return 2*(length + breadth);};
        bool isSquare();
        ~Rectangle();
};

class Cube:public Rectangle
{
    private:
        int heigth;
    public:
        Cube(int h);
        int getHeigth(){return heigth;};
        void setHeigth(int h);
        int volume();
};

int main()
{
    Cube c(5);
    c.setLength(2);
    c.setBreath(6);
    cout << c.area() << endl;
    cout << c.volume() << endl;
}

Cube::Cube(int h){
    heigth = h;
}

void Cube::setHeigth(int h){
    if(h >= 0){
        heigth = h;
    }
    else{
        heigth = 1;
    }
}

int Cube::volume(){
    return area() * heigth;
}

Rectangle::Rectangle(){
    length = 1;
    breadth = 1;
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
    if(l >= 0){
        length = l;
    }
    else{
        length = 1;
    }
}

void Rectangle::setBreath(int b){
    if(b >= 0){
        breadth = b;
    }
    else{
        breadth = 1;
    }
}

bool Rectangle::isSquare(){
    return breadth == length;
}

Rectangle::~Rectangle(){
    cout << "Object deleted" << endl;
}