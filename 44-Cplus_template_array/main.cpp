#include <iostream>

using namespace std;

template<class T>

class Array
{
private:
    T *A;
    int size;
    int lenght;

public:
    Array()
    {
        size = 10;
        lenght = 0;
        A = new T[size];
    }
    Array(int sz)
    {
        size = sz;
        lenght = 0;
        A = new T[size];
    }
    ~Array()
    {
        delete []A;
    }

    void Display();
    void Insert(int index, T x);
    T Delete(int index);

};

template<class T>
void Array<T>::Display()
{
    for(int i=0; i<lenght; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

template<class T>
void Array<T>::Insert(int index, T x)
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

template<class T>
T Array<T>::Delete(int index)
{
    T x=0;
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
    Array<int> arr(10);

    arr.Insert(0,5);
    arr.Insert(1,6);
    arr.Insert(2,9);
    arr.Display();
    cout<<arr.Delete(0)<<endl;
    arr.Display();

    return 0;
}
