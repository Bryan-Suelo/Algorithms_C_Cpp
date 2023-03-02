#include<iostream>
using namespace std;

class Car {
    public:
        virtual void start() = 0;
        virtual void stop() = 0;
};

class Innova : public Car {
    public:
        void start() {
            cout << "Innova start" << endl;
        }
        void stop() {
            cout << "Innova stop" << endl;
        }
};

class Swift : public Car {
    public:
        void start() {
            cout << "Swift start" << endl;
        }
        void stop() {
            cout << "Swift stop" << endl;
        }
};

int main() {
    Car *c = new Innova();
    c -> start();
    c -> stop();

    c = new Swift();
    c -> start();
    c -> stop();
}