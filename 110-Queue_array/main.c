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
    q->front = -1;
    q->rear = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct Queue *q, int value)
{
    if(q->rear == q->size-1)
    {
        printf("Queue is full \r\n");
    }
    else
    {
        q->rear++;
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
        q->front++;
        x = q->arr[q->front];
    }
    return x;
}

void display(struct Queue q)
{
      for(int i = q.front+1; i <= q.rear; i++)
      {
          printf("%d ", q.arr[i]);
      }
      printf("\r\n");
}

int main()
{
    struct Queue q;
    create(&q, 5);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    display(q);

    dequeue(&q);
    display(q);

    return 0;
}
