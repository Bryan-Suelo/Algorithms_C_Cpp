#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};//*first = NULL;

void Create(struct Node *p, int A[], int n)
{
    struct Node *newl, *last;
    // First element
    p->data = A[0];
    p->next = NULL;
    last = p;

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

int Max(struct Node *p)
{
    int max = -32768;
    while(p != NULL)
    {
        if(p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

int Recursive_Max(struct Node *p)
{
    int x = 0;

    if(p == NULL)
    {
        return -32768;
    }
    else
    {
        x = Recursive_Max(p->next);
        if(x > p->data)
        {
            return x;
        }
        else
        {
            return p->data;
        }
    }
}

int Recursive_2_Max(struct Node *p)
{
    int x = 0;
    if(p == NULL)
    {
        return -32768;
    }
    x = Recursive_2_Max(p->next);
    return x > p->data ? x : p->data;
}

int main()
{
    struct Node *first = NULL;
    first = (struct Node *)malloc(sizeof(struct Node));

    int A[] = {3, 5, 7, 10, 7, 5, 3};

    Create(first, A, sizeof(A)/sizeof(int));

    printf("Max number: %d\r\n", Max(first));
    printf("Recursive Max number: %d\r\n", Recursive_Max(first));
    printf("Recursive Max number: %d\r\n", Recursive_2_Max(first));
    return 0;
}
