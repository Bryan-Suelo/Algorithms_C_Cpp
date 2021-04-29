#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Create(struct Node *ptr, int A[], int n)
{
    struct Node *newl, *last;

    newl = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = A[0];
    ptr->next = NULL;
    last = ptr;

    for(int i=1; i<n; i++)
    {
        newl = (struct Node *)malloc(sizeof(struct Node));
        newl->data = A[i];
        newl->next = NULL;
        last->next = newl;
        last = newl;
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

void Merge(struct Node *ptr, struct Node *qptr)
{
    struct Node *last;

    if(ptr->data < qptr->data)
    {
        last = ptr;
        ptr = ptr->next;
        last->next = NULL;
    }
    else
    {
        last = qptr;
        qptr = qptr->next;
        last->next = NULL;
    }

    while(ptr != NULL && qptr != NULL)
    {
        if(ptr->data < qptr->data)
        {
            last->next = ptr;
            last = ptr;
            ptr = ptr->next;
            last->next = NULL;
        }
        else
        {
            last->next = qptr;
            last = qptr;
            qptr = qptr->next;
            last->next = NULL;
        }
    }

    if(ptr != NULL)
    {
        last->next = ptr;
    }
    else
    {
        last->next = qptr;
    }
    ptr = last;
}

int main()
{
    struct Node *first, *second;
    first = (struct  Node *)malloc(sizeof(struct Node));
    second = (struct  Node *)malloc(sizeof(struct Node));

    int A[] = {10, 20, 30, 40, 50};
    int B[] = {15, 25, 35, 45, 55};

    printf("First \r\n");
    Create(first, A, sizeof(A)/sizeof(int));
    Display(first);
    printf("Second \r\n");
    Create(second, B, sizeof(B)/sizeof(int));
    Display(second);

    printf("\n Merge \r\n");
    Merge(first, second);
    Display(first);

    return 0;
}
