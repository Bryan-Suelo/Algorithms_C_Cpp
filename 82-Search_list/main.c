#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first = NULL;

//void Create(struct Node *p, int A[], int n)
void Create(int A[], int n)
{
    struct Node *newl, *last;
    // Use only with TransLinearSearch
    first = (struct Node *)malloc(sizeof(struct Node));
    // First element
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

void Display(struct Node *p)
{
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\r\n");
}

struct Node *LinearSearch(struct Node *p, int key)
{
    while(p != NULL)
    {
        if(p->data == key)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

struct Node *RecursiveLinearSearch(struct Node *p, int key)
{
  if(p == NULL)
  {
      return NULL;
  }
  if(p->data == key)
  {
      return p;
  }
  return RecursiveLinearSearch(p->next, key);
}

struct Node *TransLinearSearch(struct Node *p, int key)
{
    struct Node *q = NULL;

    while(p != NULL)
    {
        if(p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

int main()
{
    //struct Node *first = NULL;
    //first = (struct Node *)malloc(sizeof(struct Node));

    int A[] = {2, 3, 5, 8, 11, 15, 19, 23, 28};
    //Create(first,  A, sizeof(A)/sizeof(int));
    Create(A, sizeof(A)/sizeof(int));

    struct Node *temp;
    //temp = LinearSearch(first, 21);
    //temp = RecursiveLinearSearch(first, 20);
    Display(first);
    printf("\r\n");
    temp = TransLinearSearch(first, 23);

    if(temp)
    {
        printf("Key is found %d\r\n", temp->data);
    }
    else
    {
        printf("Element not found\r\n");
    }

    Display(first);
    return 0;
}
