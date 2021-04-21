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

int Sum(struct Node *p)
{
    int count = 0;

    while(p != NULL)
    {
        count++;
        p = p->next;
    }
    return(count);
}

int RCount(struct Node *p)
{
    if(p == 0)
    {
        return 0;
    }
    else
    {
        return RCount(p->next) + 1;
    }
}

int main()
{
    int A[] = {8, 3, 7, 12, 9};
    Create(A, sizeof(A)/sizeof(int));

    printf("Total count: ");
    printf("%d\r\n", Sum(first));
    printf("Recursive total count: ");
    printf("%d\r\n", RCount(first));
    return 0;
}
