#include <iostream>
using namespace std;

class Queue
{
private:
    int front;
    int rear;
    int size;
    int *arr;
public:
    Queue()
    {
        front=rear=-1;
        size = 10;
        arr = new int[size];
    }
    Queue(int size)
    {
        front= rear= -1;
        this->size = size;
        arr = new int[this->size];
    }
    void enqueue(int value);
    int dequeue();
    void display();
};

void Queue::enqueue(int value)
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

int Queue::dequeue()
{
    int x = -1;
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

int main()
{
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();
    q.display();
    return 0;
}
