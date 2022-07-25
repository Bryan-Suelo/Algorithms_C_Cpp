#include <iostream>
#include "Queuecpp.h"
using namespace std;

class Tree
{
public:
    Node *root;
    Tree()
    {
        root = NULL;
    }
    void CreateTree();
    void Preorder(Node *p);
    void Postorder(Node *p);
    void Inorder(Node *p);
};

void Tree::CreateTree()
{
    Node *p, *t;
    int x;
    Queue q(100);

    printf("Enter root value");
    scanf("%d", &x);
    root = new Node;
    root->data = x;
    root->leftchild = NULL;
    root->rigthchild = NULL;
    q.enqueue(root);

    while(!q.isEmpty())
    {
        p = q.dequeue();
        printf("Enter left child of %d: ", p->data);
        scanf("%d", &x);
        if(x != -1)
        {
            t = new Node;
            t->data = x;
            t->leftchild = NULL;
            t->rigthchild = NULL;
            p->leftchild = t;
            q.enqueue(t);
        }

        printf("Enter rigth child of %d: ", p->data);
        scanf("%d", &x);
        if(x != -1)
        {
            t = new Node;
            t->data = x;
            t->leftchild = NULL;
            t->rigthchild = NULL;
            p->rigthchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::Preorder(Node *p)
{
    if(p)
    {
        printf("%d ", p->data);
        Preorder(p->leftchild);
        Preorder(p->rigthchild);
    }
}

void Tree::Postorder(Node *p)
{
    if(p)
    {
        Preorder(p->leftchild);
        Preorder(p->rigthchild);
        printf("%d ", p->data);

    }
}

int main()
{
    Tree t;
    t.CreateTree();
    t.Postorder(t.root);
    printf("\r\n");
    t.Preorder(t.root);
    return 0;
}
