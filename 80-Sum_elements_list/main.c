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
    int sum = 0;

    while(p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return(sum);
}

int RSum(struct Node *p)
{
    if(p == 0)
    {
        return 0;
    }
    else
    {
        return RSum(p->next) + p->data;
    }
}

int main()
{
    int A[] = {8, 3, 7, 12, 9};
    Create(A, sizeof(A)/sizeof(int));

    printf("Total sum: ");
    printf("%d\r\n", Sum(first));
    printf("Recursive total sum: ");
    printf("%d\r\n", RSum(first));
    return 0;
}
