#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

struct Stack
{
    int size;
    int top;
    struct Node **arr;
};

void StackCreate(struct Stack *st, int nelements)
{
    st->size = nelements;
    st->top = -1;
    st->arr = (struct Node **)malloc(sizeof(struct Node *));
}

void DisplayStack(struct Stack *st)
{
    for(int i=st->top; i>=0; i--)
    {
        printf("%d ", st->arr[i]);
    }
    printf("\r\n");
}

void Push(struct Stack *st, struct Node *nd)
{
    if(st->top == st->size-1)
    {
        printf("Stack overflow \r\n");
    }
    else
    {
        st->top++;
        st->arr[st->top] = nd;
    }
}

struct Node *Pop(struct Stack *st)
{
    int deleted = -1;

    if(st->top == -1)
    {
        printf("Stack underflow \r\n");
    }
    else
    {
        deleted = st->arr[st->top--];
    }
    return deleted;
};

int isEmptyStack(struct Stack *st)
{
    if(st->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFullStack(struct Stack *st)
{
    return st->top == st->size -1;
}

#endif // STACK_H_INCLUDED
