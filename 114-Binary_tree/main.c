#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"

struct Node *root=NULL;

void Treecreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);

    printf("Enter root value: ");
    scanf("%d", &x);
    printf("\r\n");
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->leftchild = NULL;
    root->rigthchild = NULL;
    enqueue(&q, root);

    while(!isEmpty(q))
    {
        p = dequeue(&q);

        printf("Enter left child of %d:", p->data);
        scanf("%d", &x);
        printf("\r\n");
        if(x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->leftchild = NULL;
            t->rigthchild = NULL;
            p->leftchild = t;
            enqueue(&q, t);
        }

        printf("Enter rigth child of %d:", p->data);
        scanf("%d", &x);
        printf("\r\n");
        if(x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->leftchild = NULL;
            t->rigthchild = NULL;
            p->rigthchild = t;
            enqueue(&q, t);
        }
    }
}

void Preorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        Preorder(p->leftchild);
        Preorder(p->rigthchild);
    }
}

void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->leftchild);
        printf("%d ", p->data);
        Inorder(p->rigthchild);
    }
}

void IPreorder(struct Node *p)
{
    struct Stack *st;
    StackCreate(&st, 100);

    while((p != NULL) || !isEmptyStack(&st))
    {
        if(p != NULL)
        {
            printf("%d ", p->data);
            Push(&st, p);
            p = p->leftchild;
        }
        else
        {
            p = Pop(&st);
            p = p->rigthchild;
        }
    }
}

void IInorder(struct Node *root)
{
    struct Stack *st;
    StackCreate(&st, 100);

    while(!isEmptyStack(st))
    {
        if(root)
        {
            Push(&st, root);
            root = root->leftchild;
        }
        else
        {
            root = Pop(&st);
            printf("%d ", root->data);
            root = root->rigthchild;
        }
    }
}

void LevelOrder(struct Node *root)
{
    struct Queue q;
    create(&q, 100);

    printf("%d ", root->data);
    enqueue(&q, root);

    while(!isEmpty(q))
    {
        root = dequeue(&q);
        if(root->leftchild)
        {
            printf("%d ", root->leftchild->data);
            enqueue(&q, root->leftchild);
        }
        if(root->rigthchild)
        {
            printf("%d ", root->rigthchild->data);
            enqueue(&q, root->rigthchild);
        }
    }
}

int maxValue(int inArray[], int start, int inEnd)
{
    int max = inArray[start];
    int index = start;
    for (int i=start + 1; i<= inEnd; i++)
    {
        if (inArray[i] > max)
        {
            max = inArray[i];
            index = i;
        }
    }
    return index;
}

struct Node * generateTreeTraversal(int *inorder, int inStart, int inEnd)
{
    if(inStart > inEnd)
    {
        return NULL;
    }

    int index = maxValue(inorder, inStart, inEnd);

    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = inorder[index];
    node->leftchild = NULL;
    node->rigthchild = NULL;

    if (inStart == inEnd)
    {
        return node;
    }

    node->leftchild = generateTreeTraversal(inorder, inStart, index-1);
    node->rigthchild = generateTreeTraversal(inorder, index+1, inEnd);

    return node;
}

int count(struct Node *root)
{
    if(root)
    {
        return count(root->leftchild) + count(root->leftchild) + 1;
    }
    return 0;
}

int height (struct Node *root)
{
    int x,y;

    if(root == 0)
    {
        return 0;
    }

    x = count(root->leftchild);
    y = count(root->rigthchild);

    if(x > y)
    {
        return x+1;
    }
    else
    {
        return y+1;
    }
}

int LeafNode(struct Node *root)
{
    int x, y;

    if(root != NULL)
    {
        x = LeafNode(root->leftchild);
        y = LeafNode(root->rigthchild);

        if(!root->leftchild && !root->rigthchild)
        {
            return x+y+1;
        }
        else
        {
            return x+y;
        }
    }
    return 0;
}

int Degree2(struct Node *root)
{
    int x, y;

    if(root != NULL)
    {
        x = LeafNode(root->leftchild);
        y = LeafNode(root->rigthchild);

        if(root->leftchild && root->rigthchild)
        {
            return x+y+1;
        }
        else
        {
            return x+y;
        }
    }
    return 0;
}

int Degree1(struct Node *root)
{
    int x, y;

    if(root != NULL)
    {
        x = LeafNode(root->leftchild);
        y = LeafNode(root->rigthchild);

        if(!root->leftchild ^ !root->rigthchild)
        {
            return x+y+1;
        }
        else
        {
            return x+y;
        }
    }
    return 0;
}

int main()
{
    //Treecreate();

    /*printf("Recursive Preorder: ");
    preorder(root);
    printf("\r\n");

    printf("Iterative Preorder: ");
    IPreorder(root);
    printf("\r\n");

    printf("Recursive Inorder: ");
    inorder(root);
    printf("\r\n");

    printf("Iterative Inorder: ");
    IInorder(root);
    printf("\r\n");

    printf("Iterative Level Order: ");
    LevelOrder(root);
    printf("\r\n");*/

    int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};
    int len = sizeof(inorder)/sizeof(inorder[0]);
    printf("Generate tree from traversal \r\n");
    struct Node *tree = generateTreeTraversal(inorder, 0, len-1);
    Inorder(tree);
    printf("\r\n");
    Preorder(tree);

    /*printf("Count: %d \r\n", count(root));
    printf("Height: %d \r\n", height(root));*/

    printf("Leaf nodes: %d \r\n", LeafNode(tree));
    printf("Nodes degree one: %d \r\n", Degree1(tree));
    printf("Nodes degree two: %d \r\n", Degree2(tree));

    return 0;
}
