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

int main()
{
   struct sparse sp;
   create(&sp);
   Display(sp);
    return 0;
}
