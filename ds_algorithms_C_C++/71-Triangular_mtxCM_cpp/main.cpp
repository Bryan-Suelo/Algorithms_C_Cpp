#include <iostream>

using namespace std;

class LowerTri
{
private:
    int n;
    int *A;
public:
    LowerTri()
    {
        n = 2;
        A = new int[2*(2+1)/2];
    }
    LowerTri(int n)
    {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    ~LowerTri()
    {
        delete []A;
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int GetDimension() {return n;}
};

void LowerTri::Set(int i, int j, int x)
{
        if(i >= j)
        {
            int index = (n * (j-1) - (((j-2) * (j-1))/2)) + (i-j);
            A[index] = x;
        }
}

int LowerTri::Get(int i, int j)
{
    if(i >= j)
    {
        int index = (n * (j-1) - (((j-2) * (j-1))/2)) + (i-j);
        return A[index];
    }
    else
    {
        return 0;
    }
}

void LowerTri::Display()
{
    for(int i =1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i >= j)
            {
                cout<<Get(i,j)<<" ";
            }
            else
            {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}
int main()
{

    LowerTri cm(4);

    cm.Set(1, 1, 1);
    cm.Set(2, 1, 2);
    cm.Set(2, 2, 3);
    cm.Set(3, 1, 4);
    cm.Set(3, 2, 5);
    cm.Set(3, 3, 6);
    cm.Set(4, 1, 7);
    cm.Set(4, 2, 8);
    cm.Set(4, 3, 9);
    cm.Set(4, 4, 10);

    cm.Display();

    return 0;
}
