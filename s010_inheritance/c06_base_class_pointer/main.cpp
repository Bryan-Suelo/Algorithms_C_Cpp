#include<iostream>
using namespace std;

class BasicCar{
    public:
        void start(){
            cout << "Car started" << endl;
        }
};

class AdvanceCar : public BasicCar{
    public:
        void audio(){
            cout << "Music playing" << endl;
        }
};

int main(){
    AdvanceCar a;
    a.start();
    a.audio();

    AdvanceCar ac;
    BasicCar *bptr;
    bptr = &ac;
    bptr -> start();

    return 0;
}