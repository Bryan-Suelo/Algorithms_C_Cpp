#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first = NULL;

void Create(int A[], int n)
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

int Count(struct Node *p)
{
    int element = 0;
    while(p != NULL)
    {
        element++;
        p = p->next;
    }
    return(element);
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

void Reverse(struct Node *p)
{
    int *A;
    A = (int *)malloc(sizeof(int)*Count(p));

    int i = 0;
    struct Node *q = p;

    while(q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while(q != NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}

void Reverse_sliding(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;

    while(p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void Reverse_recursing(struct Node *q, struct Node *p)
{
        if(p)
        {
            Reverse_recursing(p, p->next);
            p->next = q;
        }
        else
        {
            first = q;
        }
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    Create(A, sizeof(A)/sizeof(int));
    //Display(first);

    // Reverse(first);
    //Reverse_sliding(first);
    Reverse_recursing(NULL, first);
    Display(first);
    return 0;
}
