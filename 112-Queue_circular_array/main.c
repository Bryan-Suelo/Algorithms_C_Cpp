#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = 0;
    q->rear = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct Queue *q, int value)
{
    if((q->rear + 1)%q->size == q->front)
    {
        printf("Queue is full\r\n");
    }
    else
    {
        q->rear = (q->rear + 1)%q->size;
        q->arr[q->rear] = value;
    }
}

int dequeue(struct Queue *q)
{
    int x = -1;
    if(q->front == q->rear)
    {
        printf("Queue is empty \r\n");
    }
    else
    {
        q->front = (q->front)%q->size;
        x = q->arr[q->front];
    }
    return x;
}

void display(struct Queue q)
{
    int i = q.front+1;
    do
    {
        printf("%d ", q.arr[i]);
        i = (i+1)%q.size;
    }while(i != (q.rear+1)%q.size);
    printf("\r\n");
}

int main()
{
    struct Queue q;
    create(&q, 6);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    display(q);

    printf("%d\r\n", dequeue(&q));
    display(q);
    return 0;
}
