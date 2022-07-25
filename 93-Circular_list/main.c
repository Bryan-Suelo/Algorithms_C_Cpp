#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Create(struct Node *ptr, int A[], int Nele)
{
    struct Node *newl, *last;

    //ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = A[0];
    ptr->next = ptr;
    last = ptr;

    for(int i=1; i<Nele; i++)
    {
        newl = (struct Node *)malloc(sizeof(struct Node));
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

int main()
{
    struct Node *Head;
    Head = (struct Node *)malloc(sizeof(struct Node));

    int A[] = {1, 2, 3, 4, 5};
    Create(Head, A, sizeof(A)/sizeof(int));
    Display(Head);

    return 0;
}
