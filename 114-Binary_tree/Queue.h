#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

struct Node
{
    struct Node *leftchild;
    int data;
    struct Node *rigthchild;
};

struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **arr;
};

void create(struct Queue *q, int value)
{
    q->size = value;
    q->front = 0;
    q->rear = 0;
    q->arr = (struct Node **)malloc(q->size * sizeof(struct Node *));
}

void enqueue(struct Queue *q, struct Node *value)
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

struct Node * dequeue(struct Queue *q)
{
    struct Node *x = NULL;
    if(q->front == q->rear)
    {
        printf("Queue is empty");
    }
    else
    {
        q->front++;
        x = q->arr[q->front];
    }
    return x;
}

int isEmpty(struct Queue q)
{
    return q.front == q.rear;
}

#endif // QUEUE_H_INCLUDED
