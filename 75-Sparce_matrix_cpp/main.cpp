#include <iostream>
using namespace std;

class elements
{
public:
    int elCol;
    int elRow;
    int elNum;
};

class sparse
{
private:
    int spCol;
    int spRow;
    int spNzeroElements;
    elements *fromEtoS;
public:
    sparse(int spCol, int spRow, int spNzeroElements)
    {
        this->spCol = spCol;
        this->spRow = spRow;
        this->spNzeroElements = spNzeroElements;
        fromEtoS = new elements[this->spNzeroElements];
    }
    ~sparse()
    {
        delete []fromEtoS;
    }

    void create()
    {
        cout<<"Enter non-zero elements: "<<endl;
        for(int i=0; i<spNzeroElements; i++)
        {
            cin>>fromEtoS[i].elRow>>fromEtoS[i].elCol>>fromEtoS[i].elNum;
        }
    }

    void display()
    {
        int k=0;
        for(int i=0; i<spRow; i++)
        {
            for(int j=0; j<spCol; j++)
            {
                if(fromEtoS[k].elCol == i && fromEtoS[k].elRow == j)
                {
                    cout<<fromEtoS[k++].elNum<<" ";
                }
                else
                {
                    cout<<"0 ";
                }
            }
            cout<<endl;
        }
    }
};

int main()
{
    sparse s1(5,5,5);
    s1.create();
    s1.display();
    return 0;
}
