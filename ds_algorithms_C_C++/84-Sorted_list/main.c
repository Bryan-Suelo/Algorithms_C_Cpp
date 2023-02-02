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

void Display(struct Node *p)
{
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\r\n");
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

void SortedList(struct Node *p, int x)
{
    struct Node *temp, *q = NULL;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if(first == NULL)
    {
        first = temp;
    }
    else
    {
        while(p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if(p == first)
        {
            temp->next = first;
            first = temp;
        }
        else
        {
            temp->next = q->next;
            q->next = temp;
        }
    }
}

int main()
{
    //int A[] = {1, 2, 4, 5};

    //Create(A, sizeof(A)/sizeof(int));
    //Display(first);
    //printf("%d \r\n", Count(first));
    SortedList(first, 0);
    SortedList(first, 3);
    Display(first);
    return 0;
}
