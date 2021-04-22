#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int lenght;
};

void Display(struct Array arr)
{
       int i;
       printf("\nElements are: \n");
       for(i=0;i<arr.lenght;i++)
       {
           printf("%d ",arr.A[i]);
       }
}

void Append(struct Array *arr, int x)
{
    if (arr->lenght < arr->size)
    {
        arr->A[arr->lenght++] = x;
    }
}

void Insert(struct Array *arr, int index, int x)
{
    int i;
    if ((index >= 0) && (index <= arr->lenght))
    {
        for(i=arr->lenght; i>index; i--)
        {
            arr->A[i] = arr->A[i-1];
        }
    }
}

int Delete(struct Array *arr, int index)
{
    int i;
    int x=0;

    if((index >= 0) && (index <= arr->lenght))
    {
        x = arr->A[index];
        for(i=index; i<(arr->lenght-1); i--)
        {
            arr->A[i] = arr->A[i-1];
        }
        arr->lenght--;
        return x;
    }
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    y* = temp;
}

int LinearSearch(struct Array *arr, int key)
{
    int i;
    for(i=0; i<arr->lenght; i++)
    {
        if(key == arr->A[i])
        {
            swap(arr->A[i], arr->A[0]);
            return i;
        }
    }
    return -1;
}

int Sum(struct Array arr)
{
    int i;
    int total = 0;
    for(i=0; i<arr.lenght; i++)
    {
        total = total + arr.A[i];
    }
    return total;
}

int main()
{
    struct Array arr1;
    int ch,x,index;

    printf("Enter size of Array \n");
    scanf("%d",&arr1.size);
    arr1.A=(int *)malloc(arr1.size*sizeof(int));
    do
    {
        printf("Menu \n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter an element and index ");
                scanf("%d%d", &x, &index);
                Insert(&arr1,index,x);
                break;

            case 2:
                printf("Enter index ");
                scanf("%d", &index);
                x = Delete(&arr1, index);
                printf("Deleted element is %d\n",x);
                break;

            case 3:
                printf("Enter element to search ");
                scanf("%d",&x);
                index = LinearSearch(&arr1,x);
                printf("Element index %d", index);
                break;

            case 4:
                printf("Sum is %d\n", Sum(arr1));
                break;

            case 5:
                Display(arr1);
        }
    } while(ch<6);

    return 0;

}
