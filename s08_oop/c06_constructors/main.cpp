#include<iostream>
using namespace std;

class Rectangle
{
    private:
        int length;
        int breadth;
    
    public:
        /*Rectangle(){
            length=0;
            breadth=0;
        }*/

        Rectangle(int l=0, int b=0){
            setLength(l);
            setBreadth(b);
        }

        Rectangle(Rectangle &r){
            length = r.length;
            breadth = r.breadth;
        }

        void setLength(int l){
            if(l>=0){
                length = l;
            }
            else{
                length = 0;
            }
        }

        void setBreadth(int b){
            if(b>=0){
                breadth = b;
            }
            else{
                breadth = 0;
            }
        }

        int area(){
            return length * breadth;
        }

        int perimeter(){
            return 2*(length + breadth);
        }
};

int main()
{
    Rectangle r;
    cout << r.area() << endl;

    Rectangle r1(5,10);
    cout << r1.area() << endl;
    cout << r1.perimeter() << endl;

    Rectangle r2(r1);
    cout << r2.area() << endl;
    cout << r2.perimeter() << endl;

    return 0;
}