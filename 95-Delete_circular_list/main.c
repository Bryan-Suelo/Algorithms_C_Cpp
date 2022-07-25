#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*Head;

void Create(int A[], int totElem)
{
    struct Node *newl, *last;

    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;

    for(int i=1; i<totElem; i++)
    {
        newl = (struct  Node *)malloc(sizeof(struct Node));
        newl->data = A[i];
        newl->next = last->next;
        last->next = newl;
        last = newl;
    }
}

void Display(struct Node *ptr)
{
    struct Node *temp = ptr;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }while(ptr != temp);
    printf("\r\n");
}

int Count(struct Node *ptr)
{
    struct Node *temp = ptr;
    int count = 0;
    do
    {
        count++;
        temp = temp->next;
    }while(ptr != temp);
    return count;
}

int Delete(struct Node *ptr, int index)
{
    int x;

    if(index < 0 || index > Count(Head))
    {
        return -1;
    }

    if(index == 1)
    {
        while(ptr->next != Head)
        {
            ptr = ptr->next;
        }
        x = ptr->data;
        if(Head == ptr)
        {
            realloc(Head, 0);
            Head = NULL;
        }
        else
        {
            ptr->next = Head->next;
            realloc(Head, 0);
            Head = ptr->next;
        }
    }
    else
    {
        struct Node *temp;
        for(int i=0; i<index-2; i++)
        {
           ptr = ptr->next;
        }
        temp = ptr->next;
        ptr->next = temp->next;
        x = temp->data;
        realloc(temp, 0);
    }
    return x;
}

int main()
{
    //struct Node *Head;
    //Head = (struct Node *)malloc(sizeof(struct Node));

    int A[] = {1, 2, 3, 4, 5};
    Create(A, sizeof(A)/sizeof(int));
    Display(Head);
    printf("Total elements: %d \r\n", Count(Head));

    Delete(Head, 1);
    Display(Head);
    printf("Total elements: %d \r\n", Count(Head));

    Delete(Head, 3);
    Display(Head);
    printf("Total elements: %d \r\n", Count(Head));
    return 0;
}
