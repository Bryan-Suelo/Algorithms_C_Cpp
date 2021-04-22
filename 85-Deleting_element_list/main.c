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

int Delete(struct Node *p, int pos)
{
    struct Node *temp = NULL;
    int x = -1;

    if(pos < 1 || pos > Count(p))
    {
        return -1;
    }
    if(pos == 1)
    {
        temp = first;
        x = first->data;
        first = first->next;
        free(temp);
        return(x);
    }
    else
    {
        for(int i=0; i < pos-1; i++)
        {
            temp = p;
            p = p->next;
        }
        temp->next = p->next;
        x = p->data;
        free(p);
        return(x);
    }
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    Create(A, sizeof(A)/sizeof(int));
    Display(first);
    Delete(first, 1);
    Display(first);

    return 0;
}
