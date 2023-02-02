#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first;

void Create(int A[], int size)
{
    struct Node *newl, *last;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->prev = NULL;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i=1; i<size; i++)
    {
        newl = (struct Node *)malloc(sizeof(struct Node));
        newl->data = A[i];
        newl->next = NULL;
        newl->prev = last;
        last->next = newl;
        last = newl;
    }
}

void Display(struct Node *ptr)
{
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\r\n");
}

int Length(struct Node *ptr)
{
    int count = 0;
    while(ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

void Reverse(struct Node *ptr)
{
     struct Node *temp = NULL;

     while (ptr !=  NULL)
     {
       temp = ptr->prev;
       ptr->prev = ptr->next;
       ptr->next = temp;
       ptr = ptr->prev; // Advance to next item
     }
     if(temp != NULL)
     {
         first = temp->prev;
     }
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    Create(A, sizeof(A)/sizeof(int));
    Display(first);
    printf("Length of linked list: %d \r\n", Length(first));
    printf("\r\n");
    Reverse(first);
    Display(first);
    printf("Length of linked list: %d \r\n", Length(first));

    return 0;
}

