#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*start=NULL;

void Create(int A[], int total_elements)
{
    struct Node *new_node, *last;

    start = (struct Node *)malloc(sizeof(struct Node));
    start->data = A[0];
    start->next = NULL;
    last = start;

    for(int i=1; i<total_elements; i++)
    {
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = A[i];
        new_node->next = NULL;
        last->next = new_node;
        last = new_node;
    }
}

void Display(struct Node *ptr)
{
    while(ptr)
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

int Middle_element(struct Node *ptr)
{
    struct Node *temp = start;

    while(temp != NULL)
    {
       temp = temp->next;
       if(temp != NULL)
       {
           temp = temp->next;
       }
       if(temp != NULL)
       {
           ptr = ptr->next;
       }
    }
    return ptr->data;
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    Create(A, sizeof(A)/sizeof(int));
    Display(start);
    printf("Length of linked list: %d \r\n", Length(start));
    printf("Middle element of linked list: %d \r\n", Middle_element(start));
    return 0;
}
