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
    struct Node *last, *newl;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = NULL;
    first->next = NULL;
    last = first;

    for(int i=1; i<size; i++)
    {
        newl = (struct Node *)malloc(sizeof(struct Node));
        newl->data = A[i];
        newl->next = last->next; //NULL
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

int Delete(struct Node *ptr, int index)
{
    int value;
    if(index < 0 || index > Length(ptr))
    {
        return -1;
    }

    if(index == 1)
    {
        first = first->next;
        if(first != NULL)
        {
            first->prev = NULL;
        }
        value = ptr->data;
        free(ptr);
    }
    else
    {
        for(int i=0; i<index-1; i++)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = ptr->next;
        if(ptr->next != NULL)
        {
            ptr->next->prev = ptr->prev;
        }
        value = ptr->data;
        free(ptr);
    }
    return value;
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    Create(A, sizeof(A)/sizeof(int));
    Display(first);
    printf("Length of linked list: %d \r\n", Length(first));

    Delete(first, 1);
    Display(first);
    printf("Length of linked list: %d \r\n", Length(first));

    Delete(first, 3);
    Display(first);
    printf("Length of linked list: %d \r\n", Length(first));
    return 0;
}
