#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

int BinSearch(struct Array arr, int key)
{
        int l, mid, h;
        l = 0;
        h = arr.length - 1;

        while(l <= h)
        {
            mid = (l + h) / 2;

            if ( key == arr.A[mid])
            {
                return mid;
            }
            else if (key < arr.A[mid])
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }

        }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
