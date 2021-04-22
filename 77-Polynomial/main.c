#include <stdio.h>
#include <stdlib.h>

struct Term
{
    int coeff;
    int expn;
};

struct Polynomial
{
    int numElements;
    struct Term *terms;
};

void create(struct Polynomial *poly)
{
    printf("Number of terms: ");
    scanf("%d", &poly->numElements);

    poly->terms = (struct Term *)malloc(poly->numElements * sizeof(struct Term));
    printf("Enter polynomial terms: \r\n");
    for(int i=0; i < poly->numElements; i++)
    {
        scanf("%d %d", &poly->terms[i].coeff, &poly->terms[i].expn);
    }
}

void display(struct Polynomial poly)
{
    printf("\r\n");
    for(int i=0; i < poly.numElements; i++)
    {
        printf("%dx%d + ", poly.terms[i].coeff, poly.terms[i].expn);
    }
    printf("\r\n");
}

struct Polynomial *add(struct Polynomial *p1, struct Polynomial *p2)
{
    struct Polynomial *sum;
    sum = (struct Polynomial *)malloc(sizeof(struct Polynomial));
    sum->terms = (struct Term *)malloc((p1->numElements + p2->numElements)* sizeof(struct Term));

    int i,j,k;
    i = j = k = 0;

    while(i < p1->numElements && j < p2->numElements)
    {
        if(p1->terms[i].expn > p2->terms[j].expn)
        {
            sum->terms[k++] = p1->terms[i++];
        }
        else if(p1->terms[i].expn < p2->terms[j].expn)
        {
            sum->terms[k++] = p2->terms[j++];
        }
        else
        {
            sum->terms[k].expn = p1->terms[i].expn;
            sum->terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff;
        }
    }

    for(; i < p1->numElements; i++)
    {
        sum->terms[k++] = p1->terms[i];
    }
    for(; j < p2->numElements; j++)
    {
        sum->terms[k++] = p2->terms[j];
    }

    sum->numElements = k;
    return sum;
}

int main()
{
    struct Polynomial p1, p2, *p3;

    create(&p1);
    create(&p2);

    p3 = add(&p1, &p2);

    printf("\n");
    display(p1);
    printf("\n");
    display(p2);
    printf("\n");
    display(*p3);

    return 0;
}
