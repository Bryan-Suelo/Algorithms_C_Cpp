#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first = NULL;

void Create(int A[], int TotElements)
{
    struct Node *temp, *last;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->prev = NULL;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i=1; i<TotElements; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = last->next;
        temp->prev = last;
        last->next = temp;
        last = temp;
    }
}

void Display(struct Node *ptr)
{
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\r\n");
}

int Length(struct Node *ptr)
{
    int count = 0;
    while(ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

void Insert(struct Node *ptr, int index, int value)
{
    struct Node *temp;

    if(index < 0 || index > Length(first))
    {
        return;
    }

    if(index == 0)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->prev = NULL;
        temp->data = value;
        temp->next = first;
        first->prev = temp;
        first = temp;
    }
    else
    {
        for(int i=0; i<index-1; i++)
        {
            ptr = ptr->next;
        }
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = value;
        temp->prev = ptr;
        temp->next = ptr->next;
        ptr->next = temp;
        if(ptr->next != NULL)
        {
            ptr->next->prev = temp;
        }
    }
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};

    Create(A, sizeof(A)/sizeof(int));
    Display(first);
    printf("Length is: %d\r\n\r\n", Length(first));

    Insert(first, 0, 5);
    Display(first);
    printf("Length is: %d\r\n", Length(first));

    return 0;
}
