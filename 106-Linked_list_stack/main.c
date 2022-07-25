#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*top = NULL;

void Push(int value)
{
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));

    if(temp == NULL)
    {
        printf("Stack is full \r\n");
    }
    else
    {
        temp->data = value;
        temp->next = top;
        top = temp;
    }
}

int Pop()
{
    struct Node *temp;
    int x = -1;

    if(top == NULL)
    {
        printf("Stack is empty \r\n");
    }
    else
    {
        temp = top;
        top = top->next;
        x = temp->data;
        free(temp);
    }
    return x;
}

int Peek(int position)
{
    struct Node *temp = top;

    for(int i=0; temp != NULL && i<position-1; i++)
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

void Display()
{
    struct Node *temp;
    temp = top;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\r\n");
}

int main()
{
    Push(5);
    Push(10);
    Push(15);
    Push(20);
    Push(25);
    Display();

    printf("Element peek: %d \r\n", Peek(3));
    printf("Value deleted: %d \r\n", Pop());
    Display();

    return 0;
}
