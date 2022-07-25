#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int col;
    int data;
    struct Node *next;
}*Arr[5] = {0};

void Create(int row, int column, int value)
{
    struct Node *newl, *last=NULL;
    newl = (struct Node *)malloc(sizeof(struct Node));
    newl->col = column;
    newl->data = value;
    newl->next = NULL;
    //last->next = newl;

    if (Arr[row] != NULL)
    {
        Arr[row] = (struct Node *)malloc(sizeof(struct Node));
        Arr[row] = newl;
        last = newl;
    }
    else
    {
        last->next = newl;
        last = newl;
    }
}

void display_Matrix(int columns)
{
    struct Node *ptr;

    for(int i=0; i<(sizeof(ptr) / sizeof(int)); i++)
    {
        ptr = Arr[i];
        for(int j=0; j<columns; j++)
        {
            if(j == ptr->col)
            {
                printf("%d ", ptr->data);
                ptr = ptr->next;
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\r\n");
    }
}

int main()
{
    Create(0,4,8);
    Create(1,3,7);
    //Create(2,0,5);
    Create(2,4,9);
    Create(3,5,3);
    //Create(4,0,6);
    Create(4,3,4);

    //Display(Arr);
    display_Matrix(6);
    return 0;
}
