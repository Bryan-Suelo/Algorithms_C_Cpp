#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first = NULL;

void create(int A[], int n)
{
    struct Node *newl, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i=1; i<n; i++)
    {
        newl = (struct Node *)malloc(sizeof(struct Node));
        newl->data = A[i];
        newl->next = NULL;
        last->next = newl;
        last = newl;
    }
}

void Display(struct Node *p)
{
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\r\n");
}

void Remove(struct Node *p)
{
    struct Node *q = p->next;
    while(q != NULL)
    {
        if(p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

int main()
{
    int A[] = {10,10, 20, 30, 30, 30, 40, 40, 50};
    create(A, sizeof(A)/sizeof(int));
    printf("First list: \r\n");
    Display(first);
    printf("\r\n");
    printf("Removed elements list: \r\n");
    Remove(first);
    Display(first);
    return 0;
}
