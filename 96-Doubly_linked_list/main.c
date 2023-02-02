#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

void Create(struct Node *first, int A[], int TotElements)
{
    struct Node *temp, *last;

    first->prev = NULL;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i=1; i<TotElements; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = last->next; // last->next = NULL (line 17 and 18)
        temp->prev = last;
        last->next = temp;
        last = temp;
    }
}

void Display(struct Node *first)
{
    while(first != NULL)
    {
        printf("%d ", first->data);
        first = first->next;
    }
    printf("\r\n");
}

int Length(struct Node *first)
{
    int count = 0;
    while(first != NULL)
    {
        count++;
        first = first->next;
    }
    return count;
}
int main()
{
    struct Node *first;
    first = (struct Node *)malloc(sizeof(struct Node));
    int A[] = {10, 20, 30, 40, 50};

    Create(first, A, sizeof(A)/sizeof(int));
    Display(first);

    return 0;
}
