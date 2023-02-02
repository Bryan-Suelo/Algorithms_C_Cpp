#include <iostream>

using namespace std;

class Array
{
private:
    int *A;
    int size;
    int lenght;
    void Swap(int *x, int *y);
public:
    Array()
    {
        size = 10;
        lenght = 0;
        A = new int[size];
    }
    Array(int sz)
    {
        size = sz;
        lenght = 0;
        A = new int[size];
    }
    ~Array()
    {
        delete []A;
    }

    void Display();
    void Insert(int index, int x);
    int Delete(int index);

};

void Array::Display()
{
    for(int i=0; i<lenght; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}


void Array::Insert(int index, int x)
{
    int i;
    if((index>=0) && (index<=lenght))
    {
        for(i=lenght; i>=index; i--)
        {
            A[i] = A[i-1];
        }
        A[index] = x;
        lenght++;
    }
}

int Array::Delete(int index)
{
    int x=0;
    if((index>=0) && (index<=lenght))
    {
        x = A[index];
        for(int i=index; i<lenght-1;i++)
        {
            A[i]=A[i+1];
        }
        lenght--;
    }
    return x;
}

int main()
{
    Array arr(10);

    arr.Insert(0,5);
    arr.Insert(1,6);
    arr.Insert(2,9);
    arr.Display();
    cout<<arr.Delete(0)<<endl;
    arr.Display();

    return 0;
}
