#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void Create(int A[], int size)
{
    struct Node *newl, *last;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = first;
    first->next = first;
    last = first;

    for(int i=1; i<size; i++)
    {
        newl = (struct Node *)malloc(sizeof(struct Node));
        newl->data = A[i];
        newl->next = last->next;
        first->prev = newl;
        newl->prev = last->prev;
        last->next = newl;
        last = newl;
    }
}

void Display(struct Node *ptr)
{
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }while(ptr != first);
    printf("\r\n");
}

int Length(struct Node *ptr)
{
    int count=0;
    do
    {
        count++;
        ptr = ptr->next;
    }while(ptr != first);
    return count;
}

void Insert(struct Node *ptr, int index, int value)
{
    struct Node *newl = NULL;

    if(index < 0 || index > Length(ptr))
    {
        return;
    }

    if(value == 0)
    {
        newl = (struct Node *)malloc(sizeof(struct Node));
        newl->data = value;
        newl->next = ptr;
        newl->prev = ptr;
        ptr->prev->next = newl;
        ptr->prev = newl;
        ptr = newl;
    }
    else
    {
        for(int i=0; i<index-1; i++)
        {
            ptr = ptr->next;
        }
        newl = (struct Node *)malloc(sizeof(struct Node));
        newl->data = value;
        newl->prev = ptr;
        newl->next = ptr->next;
        ptr->next = newl;
        if(ptr->next != NULL)
        {
            ptr->next->prev = newl;
        }
    }
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    Create(A, sizeof(A)/sizeof(int));
    printf("Length of list: %d \r\n", Length(first));
    Display(first);
    printf("\r\n");

    Insert(first, 0, 5);
    printf("Length of list: %d \r\n", Length(first));
    Display(first);
    printf("\r\n");

    Insert(first, 4, 25);
    printf("Length of list: %d \r\n", Length(first));
    Display(first);
    printf("\r\n");
    return 0;
}
