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
    // First element
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    // Remaining elements, final gets NULL at next
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
    int count = 0;
    while(p != NULL)
    {
        count++;
        p = p->next;
    }
    return(count);
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

void Insert(struct Node *p, int index, int x)
{
    if(index < 0 || index > Count(p))
    {
        return;
    }

    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if(index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for(int i=0; i < index-1; i++)
        {
            p = p->next;
        }
        if(p)
        {
            t->next = p->next;
            p->next = t;
        }
    }
}

int main()
{
/*    int A[] = {5,7,9};
    Create(A, sizeof(A)/sizeof(int));
    Insert(first, 0, 10);
    Insert(first, 1, 8);
    Insert(first, 8, 8);*/

    Insert(first, 0, 10);
    Insert(first, 1, 11);
    Display(first);
    return 0;
}
