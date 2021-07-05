#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int expn;
    struct Node *next;
}*poly=NULL;

void Create()
{
    struct Node *newl, *last=NULL;
    int num;

    printf("enter number of terms: ");
    scanf("%d", &num);
    printf("enter each term with coefficient and exponent\r\n");

    for(int i=0; i<num; i++)
    {
        newl = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d %d", &newl->coeff, &newl->expn);
        newl->next = NULL;

        if(poly == NULL)
        {
            poly = last = newl;
        }
        else
        {
            last->next = newl;
            last = newl;
        }
    }
}

void Display(struct Node *ptr)
{
    while(ptr != NULL)
    {
        printf("%dx%d + ", ptr->coeff, ptr->expn);
        ptr = ptr->next;
    }
    printf("\r\n");
}

long Eval(struct Node *ptr, int power)
{
    long val=0.0;

    while(ptr != NULL)
    {
        val+=ptr->coeff*pow(power, ptr->expn);
        ptr = ptr->next;
    }
    return val;
}

int main()
{
    Create();
    Display(poly);
    printf("%ld", Eval(poly, 1));

    return 0;
}
