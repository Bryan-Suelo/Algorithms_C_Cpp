#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *next;
}*top = NULL;

void Push(char value)
{
    struct  Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));

    if(temp == NULL)
    {
        printf("Stack overflow");
    }
    else
    {
        temp->data = value;
        temp->next = top;
        top = temp;
    }
}

char Pop()
{
    struct Node *temp;
    char element = -1;

    if(top == NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        temp = top;
        top = top->next;
        element = temp->data;
        free(temp);
    }
    return element;
}

int isEmpty()
{
    if(top != NULL)
    {
        return 0;
    }
    return 1;
}

void Display()
{
    struct Node *temp = top;

    while(temp != "NULL")
    {
        printf("%c", temp->data);
        temp = temp->next;
    }
    printf("\r\n");
}

int isBalanced(char *exp)
{
    for(int i=0; exp[i] != '\0'; i++)
    {
        if(exp[i] == "(")
        {
            Push(exp[i]);
        }
        else if(exp[i] == ")")
        {
            if(isEmpty())
            {
                return 0;
            }
            Pop();
        }
    }
    return isEmpty()?1:0;
}

int main()
{
    char *exp = "((a+b)*(c+d))";
    printf("%d \r\n", isBalanced(exp));

    return 0;
}
