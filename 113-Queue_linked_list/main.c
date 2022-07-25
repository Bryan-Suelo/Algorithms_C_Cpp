#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*front=NULL, *rear=NULL;

void enqueue(int value)
{
        struct Node *t;
        t = (struct Node *)malloc(sizeof(struct Node));
        if(t == NULL)
        {
            printf("Queue is full \r\n");
        }
        else
        {
            t->data = value;
            t->next = NULL;
            if(front == NULL)
            {
                front = rear = t;
            }
            else
            {
                rear->next = t;
                rear = t;
            }
        }
}

int dequeue()
{
    int x = -1;
    struct Node *t;
    if(front ==NULL)
    {
        printf("Queue is empty \r\n");
    }
    else
    {
        t = front;
        x = front->data;
        front = front->next;
        free(t);
    }
    return x;
}

void display()
{
    struct Node *p = front;
    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\r\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    printf("%d \r\n", dequeue());
    display();
    return 0;
}
