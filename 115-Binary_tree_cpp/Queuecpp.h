#include <iostream>
using namespace std;
#ifndef QUEUECPP_H_INCLUDED
#define QUEUECPP_H_INCLUDED

class Node
{
public:
    Node *leftchild;
    int data;
    Node *rigthchild;
};

class Queue
{
private:
    int front;
    int rear;
    int size;
    Node **arr;
public:
    Queue()
    {
        front=rear=-1;
        size = 10;
        arr = new Node*[size];
    }
    Queue(int size)
    {
        front= rear= -1;
        this->size = size;
        arr = new Node*[this->size];
    }
    void enqueue(Node *value);
    int isEmpty()
    {
        return front==rear;
    }
    Node * dequeue();
    void display();
};

void Queue::enqueue(Node *value)
{
    if(rear == size-1)
    {
        cout << "Queue is full" << endl;
    }
    else
    {
        rear++;
        arr[rear] = value;
    }
}

Node * Queue::dequeue()
{
    Node *x = NULL;
    if(front == rear)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        front++;
        x = arr[front];
    }
    return x;
}

void Queue::display()
{
    for(int i=front+1; i <= rear; i++)
    {
        printf("%d ", arr[i]);
    }
    cout<<"\r\n";
}

#endif // QUEUECPP_H_INCLUDED
