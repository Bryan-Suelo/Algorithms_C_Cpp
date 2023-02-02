#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *first;
public:
    LinkedList() { first = NULL; }
    LinkedList(int A[], int n);
    ~LinkedList();

    void Display();
    void Insert(int index, int x);
    int Delete(int index);
    int Count();
};

LinkedList::LinkedList(int A[], int n)
{
    Node *newl, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i=1; i<n; i++)
    {
        newl = new Node;
        newl->data = A[i];
        newl->next = NULL;
        last->next = newl;
        last = newl;
    }
}

LinkedList::~LinkedList()
{
    Node *ptr = first;
    while(first)
    {
        first = first->next;
        delete ptr;
        ptr = first;
    }
}

void LinkedList::Display()
{
    Node *ptr=first;
    while(ptr != NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

int LinkedList::Count()
{
    Node *ptr=first;
    int count = 0;
    while(ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    LinkedList l(A, sizeof(A)/sizeof(int));
    cout<<l.Count()<<endl;
    l.Display();
    return 0;
}
