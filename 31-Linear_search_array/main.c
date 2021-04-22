#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    for (i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

int Linear_search(struct Array arr, int key)
{
        int i;
        for (i = 0; i < arr.length; i++)
        {
            if (key == arr.A[i])
            {
                return i;
            }
        }
        return -1;
}

int main()
{
    struct Array arr = {{1,2,3,4,5}, 10, 5};

    printf("%d\r\n",Linear_search(arr, 2));
    Display(arr);
    return 0;
}
