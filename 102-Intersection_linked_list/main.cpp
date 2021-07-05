#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

Node* first = new Node;
Node* second = new Node;

void Create(int A[], int totalElements)
{
    Node* last;
    Node* newl;

    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i=1; i<totalElements; i++)
    {
        newl = new Node;
        newl->data = A[i];
        newl->next = NULL;
        last->next = newl;
        last = newl;
    }
}

void Create_second(int A[], int totalElements, Node* ptr)
{
    Node* last;
    Node* newl;

    second->data = A[0];
    second->next = NULL;
    last = second;

    for(int i=1; i<totalElements; i++)
    {
        newl = new Node;
        newl->data = A[i];
        newl->next = NULL;
        last->next = newl;
        last = newl;
    }
    last->next = ptr;
}

void Intersection(Node* q, Node* p)
{
    stack<Node*> stk1;
    while(p != nullptr)
    {
        stk1.push(p);
        p = p->next;
    }

    stack<Node*> stk2;
    while(q != nullptr)
    {
        stk2.push(q);
        q = q->next;
    }

    Node *r;
    while(stk1.top() == stk2.top())
    {
        r = stk1.top();
        stk1.pop();
        stk2.pop();
    }
    cout<<"Intersecting Node: " << r->data << endl;
}

int main()
{
    // Create First Linked List
    int A[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
    Create(A, sizeof(A)/sizeof(int));

    // Create Second Linked List
    Node* temp = first;
    int i = 5;
    while (i>0){
        temp = temp->next;
        i--;
    }
    cout << temp->data << endl;

    int B[] = {2, 4, 6, 8, 10};
    Create_second(B, sizeof(B)/sizeof(B[0]), temp);

    // Find Intersection
    Intersection(first, second);
    return 0;
}
