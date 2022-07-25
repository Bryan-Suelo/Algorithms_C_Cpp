#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *S;
};

void Create(struct stack *st, int elements)
{
    st->size = elements;
    st->top = -1;
    st->S = (int *)malloc(st->size*sizeof(int));
}

void Display(struct stack *st)
{
    for(int i=st->top; i>=0; i--)
    {
        printf("%d ", st->S[i]);
    }
    printf("\r\n");
}

void Push(struct stack *st, int value)
{
    if(st->top == st->size-1)
    {
        printf("Stack overflow \r\n");
    }
    else
    {
        st->top++;
        st->S[st->top] = value;
    }
}

int Pop(struct stack *st)
{
    int deleted = -1;
    if(st->top == -1)
    {
        printf("Stack underflow");
    }
    else
    {
        deleted = st->S[st->top--];
    }
    return deleted;
}

int main()
{
    struct stack *st;
    Create(st,5);

    Push(st,10);
    Push(st,20);
    Push(st,30);
    Push(st,40);
    Push(st,50);
    Display(st);

    printf("Element deleted: %d\r\n",Pop(st));
    Display(st);
    return 0;
}