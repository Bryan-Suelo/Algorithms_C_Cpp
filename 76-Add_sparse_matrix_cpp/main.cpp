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

    // Add function
    sparse operator+(sparse &sp);
    // Create function
    friend istream & operator>>(istream &is, sparse &sp);
    // display function
    friend ostream  & operator<<(ostream &os, sparse &sp);

};

sparse sparse::operator+(sparse &sp)
{
/*  if(spRow != sp.spRow && spCol != sp.spCol)
    {
        return NULL;
    }
*/
    int i , j, k;
    i= j= k=0;
    sparse *sum = new sparse(spRow, spCol, spNzeroElements+sp.spNzeroElements);

    while(i <spNzeroElements && j <spNzeroElements)
    {
        if(fromEtoS[i].elRow < sp.fromEtoS[j].elRow)
        {
            sum->fromEtoS[k++] = fromEtoS[i++];
        }
        else if(fromEtoS[i].elRow > sp.fromEtoS[j].elRow)
        {
            sum->fromEtoS[k++] = sp.fromEtoS[j++];
        }
        else
        {
            if(fromEtoS[i].elCol < sp.fromEtoS[j].elCol)
            {
                sum->fromEtoS[k++] = fromEtoS[i++];
            }
            else if(fromEtoS[i].elCol > sp.fromEtoS[j].elCol)
            {
                sum->fromEtoS[k++] = fromEtoS[j++];
            }
            else
            {
                sum->fromEtoS[k] = fromEtoS[i];
                sum->fromEtoS[k++].elNum = fromEtoS[i++].elNum + sp.fromEtoS[j++].elNum;
            }
        }
    }

    for(; i<spNzeroElements; i++)
    {
        sum->fromEtoS[k++] = fromEtoS[i];
    }
    for(; j<sp.spNzeroElements; j++)
    {
        sum->fromEtoS[k++] = sp.fromEtoS[j];
    }

    sum->spRow = spRow;
    sum->spCol = spCol;
    sum->spNzeroElements = k;

    return *sum;
}

istream & operator>>(istream &is, sparse &sp)
{
    cout<<"Enter non-zero elements: "<<endl;
    for(int i=0; i<sp.spNzeroElements; i++)
    {
        cin>>sp.fromEtoS[i].elRow>>sp.fromEtoS[i].elCol>>sp.fromEtoS[i].elNum;
    }
    return is;
}

ostream  & operator<<(ostream &os, sparse &sp)
{
    int k=0;
    for(int i=0; i<sp.spRow; i++)
    {
        for(int j=0; j<sp.spCol; j++)
        {
            if(sp.fromEtoS[k].elCol == i && sp.fromEtoS[k].elRow == j)
            {
                cout<<sp.fromEtoS[k++].elNum<<" ";
            }
            else
            {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
    return os;
}


int main()
{
    sparse s1(5,5,5);
    sparse s2(5,5,5);
    cin>>s1;
    cin>>s2;

    sparse sum=s1+s2;
    cout<<"First matrix"<<endl<<s1<<endl;
    cout<<"Second matrix"<<endl<<s2<<endl;
    cout<<"Sum matrix"<<endl<<sum;

    return 0;
}
