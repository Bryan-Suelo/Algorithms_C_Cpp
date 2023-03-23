#include<iostream>
using namespace std;

template <class T>
class Stack {
    private:
        T *stk;
        int top;
        int size;

    public:
        Stack(int sz) {
            size = sz;
            top = -1;
            stk = new T[size];
        }

        void push(T x);
        T pop();
};

template <class T>
void Stack::push(T x) {
    if (top == size -1) {
        cout<< "Stack is full" << endl;
    }
    else {
        top++;
        stk[top] = x;
    }
}

template <class T>
T Stack::pop() {
    T x = 0;
    if(top == -1) {
        cout << "Stack is empty" << endl;
    }
    else {
        x = stk[top];
        top--;
    }
    return x;
}

int main() {
    Stack s(10);
    s.push(10);
    s.push(23);
    s.push(23);
}