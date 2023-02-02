#include <stdio.h>
#include <stdlib.h>

struct element
{
    int elColumn;
    int elRow;
    int elNum;
};

struct sparse
{
    int spColumn;
    int spRow;
    int spNzeroElements;
    struct element *fromEtoS;
};

void create(struct sparse *sp)
{
     printf("Enter dimensions: ");
     scanf("%d %d", &sp->spRow, &sp->spColumn);
     printf("\r\nEnter non-zero elements: ");
     scanf("%d", &sp->spNzeroElements);

     sp->fromEtoS = (struct element *)malloc(sp->spNzeroElements * sizeof(struct element));
     printf("\r\nEnter location and value: \r\n");
     for(int i= 0; i< sp->spNzeroElements; i++)
     {
         scanf("%d %d %d", &sp->fromEtoS[i].elRow, &sp->fromEtoS[i].elColumn, &sp->fromEtoS[i].elNum);
     }
}

void Display(struct sparse sp)
{
    int k = 0;
    for(int i=0; i < sp.spRow; i++)
    {
        for(int j=0; j < sp.spColumn; j++)
        {
            if(i == sp.fromEtoS[k].elRow && j == sp.fromEtoS[k].elColumn)
            {
                printf("%d ", sp.fromEtoS[k++].elNum);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

struct sparse * add(struct sparse *s1, struct sparse *s2)
{
    struct sparse *sum;
    sum = (struct sparse *)malloc(sizeof(struct sparse));
    sum->fromEtoS = (struct element *) malloc((s1->spNzeroElements + s2->spNzeroElements) * sizeof(struct element));

    int i, j, k;
    i = j = k = 0;
    while( i < s1->spNzeroElements && j < s2->spNzeroElements)
    {
        if (s1->fromEtoS[i].elRow < s2->fromEtoS[j].elRow)
        {
            sum->fromEtoS[k++] = s1->fromEtoS[i++];
        }
        else if(s1->fromEtoS[i].elRow > s2->fromEtoS[j].elRow)
        {
            sum->fromEtoS[k++] = s2->fromEtoS[j++];
        }
        else
        {
            if(s1->fromEtoS[i].elColumn < s2->fromEtoS[j].elColumn)
            {
                sum->fromEtoS[k++] = s1->fromEtoS[i++];
            }
            else if(s1->fromEtoS[i].elColumn > s2->fromEtoS[j].elColumn)
            {
                sum->fromEtoS[k++] = s2->fromEtoS[j++];
            }
            else
            {
                sum->fromEtoS[k] = s1->fromEtoS[i];
                sum->fromEtoS[k++].elNum = s1->fromEtoS[i++].elNum + s2->fromEtoS[j++].elNum;
            }
        }
    }
    for (;i<s1->spNzeroElements; i++)
    {
        sum->fromEtoS[k++] = s1->fromEtoS[i];
    }
    for (;j<s2->spNzeroElements; j++)
    {
        sum->fromEtoS[k++] = s2->fromEtoS[j];
    }
    sum->spRow = s1->spRow;
    sum->spColumn = s1->spColumn;
    sum->spNzeroElements = k;
}

int main()
{
   struct sparse s1, s2, *s3;

   create(&s1);
   create(&s2);

   s3 = add(&s1, &s2);
   printf("First matrix: \n");
   Display(s1);
    printf("Second matrix: \n");
   Display(s2);
   printf("Sum matrix: \n");
   Display(*s3);
    return 0;
}
