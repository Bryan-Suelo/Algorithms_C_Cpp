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

    //ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = A[0];
    ptr->next = NULL;
    last= ptr;

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

int isLoop(struct Node *ptr)
{
    struct Node *qptr;
    qptr = ptr;

    do
    {
        ptr = ptr->next;
        qptr = qptr->next;
        qptr = qptr != NULL ? qptr->next : NULL;
    }while((ptr != NULL && qptr != NULL) && ptr != qptr);

    return (ptr == qptr ? 1:0);

 /*   if(ptr == qptr)
    {
        return 1;
    }
    else
    {
        return 0;
    }*/
}

int main()
{
    struct Node *first, *t1, *t2;
    first = (struct  Node *)malloc(sizeof(struct Node));

    int A[] = {10, 20, 30, 40, 50};
    Create(first, A, sizeof(A)/sizeof(int));
    Display(first);

    t1 = first->next->next; // 30
    t2 = first->next->next->next->next; // 50
    t2->next = t1;

    printf("Result: %d \r\n", isLoop(first));
    return 0;
}
