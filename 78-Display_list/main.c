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

void Display(struct Node *p)
{
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\r\n");
}

void RecursiveDisplay(struct Node *p)
{
    if(p != NULL)
    {
        /* Data is printed in reverse
        RecursiveDisplay(p->next);
        printf("%d ", p->data);*/

        // Data printed in order
        printf("%d ", p->data);
        RecursiveDisplay(p->next);
    }
}

int main()
{
    int A[] = {8, 3, 7, 12, 9};
    Create(A, sizeof(A)/ sizeof(int));
    Display(first);
    RecursiveDisplay(first);

    return 0;
}
