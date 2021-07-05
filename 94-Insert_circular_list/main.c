#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Create(struct Node *ptr, int A[], int n)
{
    struct Node *newl, *last;

    ptr->data = A[0];
    ptr->next = ptr;
    last = ptr;

    for(int i=1; i<n; i++)
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

void Insert(struct Node *ptr, int index, int element)
{
    struct Node *temp;
    struct Node *Head = ptr;

/*    if(index < 0 || index > Count(ptr))
    {
        return;
    }
*/
    if(index == 0)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = element;

        if(ptr == NULL)
        {
            ptr = temp;
            ptr->next = ptr;
        }
        else
        {
            while(ptr->next != Head)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
            temp->next = Head;
            //Head = temp;
        }
    }
    else
    {
        for(int i=0; i<index-1; i++)
        {
            ptr = ptr ->next;
        }
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = element;
        temp->next = ptr->next;
        ptr->next= temp;
    }
}

int main()
{
    struct Node *Head;
    Head = (struct Node *)malloc(sizeof(struct Node));
    int A[] = {1, 2, 3, 4, 5};
    Create(Head, A, sizeof(A)/sizeof(int));
    Display(Head);
    printf("Total elements: %d \r\n", Count(Head));

    Insert(Head, 0, 10);
    Display(Head);
    printf("Total elements: %d \r\n", Count(Head));

    return 0;
}
