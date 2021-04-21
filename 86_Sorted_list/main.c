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

        for(int i=1; i < n; i++)
        {
            newl = (struct Node *)malloc(sizeof(struct Node));
            newl->data = A[i];
            newl->next = NULL;
            last->next = newl;
            last = newl;
        }
}

int isSorted(struct Node *p)
{
    int x = -65535;
    while(p != NULL)
    {
        if(p->data < x)
        {
            return 0;
        }
        x = p->data;
        p = p->next;
    }
    return 1;
}

int main()
{
    int A[] = {10, 20, 30, 20, 50};
    Create(A, sizeof(A)/sizeof(int));
    if(isSorted(first))
    {
        printf("List is sorted\r\n");
    }
    else
    {
        printf("Not sorted list");
    }
    return 0;
}
