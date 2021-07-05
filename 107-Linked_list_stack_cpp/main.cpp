#include <iostream>
#include <stdlib.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;
public:
    Stack(){top = NULL;}
    void Push(int value);
    int Pop();
    int Peek(int position);
    void Display();
};

void Stack::Push(int value)
{
    Node *temp = new Node;
    if(temp == NULL)
    {
        cout<<"Stack overflow"<<endl;
    }
    else
    {
        temp->data = value;
        temp->next = top;
        top = temp;
    }
}

int Stack::Pop()
{
    int x = -1;
    Node *temp = new Node;
    if(top == NULL)
    {
        cout<<"Stack is empty"<<endl;
    }
    else
    {
        temp = top;
        top = top->next;
        x = temp->data;
        delete temp;
    }
    return x;
}

int Stack::Peek(int position)
{
    Node *temp = top;

    for(int i=0; temp != NULL && i < position-1; i++)
    {
        temp = temp->next;
    }
    if(temp != NULL)
    {
        return temp->data;
    }
    else
    {
        return -1;
    }
}

void Stack::Display()
{
    Node *temp = top;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    Stack stk;

    stk.Push(10);
    stk.Push(20);
    stk.Push(30);
    stk.Push(40);

    stk.Display();

    cout << stk.Peek(3)<<endl;
    stk.Push(50);

    cout<<stk.Pop();
    return 0;
}
