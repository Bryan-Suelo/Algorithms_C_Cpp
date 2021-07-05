#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data;
    struct  Node *next;
}*top = NULL;

void Push(char value)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));

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
        printf("Stack is empty\r\n");
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

int Pre(char chr)
{
    if(chr == '+' || chr == '-')
    {
        return 1;
    }
    else if(chr == '*' || chr == '/')
    {
        return 2;
    }
    return 0;
}

int isOperand(char chr)
{
    if(chr == '+' || chr == '-' || chr == '*' || chr == '/')
    {
        return 0;
    }
    return 1;
}

char * InToPost(char *infix)
{
    char *postfix;
    unsigned long len = strlen(infix);
    postfix = (char *)malloc((len+1) * sizeof(char));

    int i=0, j=0;
    while(infix[i] != '\0')
    {
        if(isOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if(Pre(infix[i]) > Pre(top->data))
            {
                Push(infix[i++]);
            }
            else
            {
                postfix[j++] = Pop();
            }
        }
    }
    while(top != NULL)
    {
        postfix[j++] = Pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "a+b*c";
    Push('#');

    char *postfix = InToPost(infix);
    printf("%s", postfix);
    return 0;
}
