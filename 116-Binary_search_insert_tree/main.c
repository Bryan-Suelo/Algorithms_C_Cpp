#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *lchild;
    struct Node *rchild;
    int data;
}*root = NULL;

void Insert(int key){
    struct Node *tNode = root;
    struct Node *nNode = NULL;
    struct Node *itNode  = NULL;

    if(root == NULL){
        nNode = (struct Node *)malloc(sizeof(struct Node));
        nNode->data = key;
        nNode->lchild = nNode->rchild = NULL;
        root = nNode;
        return;
    }

    while(tNode != NULL)
    {
        itNode = tNode;
        if(key < tNode->data){
            tNode = tNode->lchild;
        }
        else if(key > tNode->data){
            tNode = tNode->rchild;
        }
        else{
            return;
        }
    }

    nNode = (struct Node *)malloc(sizeof(struct Node));
    nNode->data = key;
    nNode->lchild = nNode->rchild = NULL;

    if(key < itNode->data){
        itNode->lchild = nNode;
    }
    else{
        itNode->rchild = nNode;
    }
}

struct Node *rInsert(struct Node *tNode, int key){
    struct Node *nNode;

    if (tNode == NULL){
            nNode = (struct Node *)malloc(sizeof(struct Node));
            nNode->data = key;
            nNode->lchild = nNode->rchild = NULL;
            return nNode;
    }
    if(key < tNode->data){
        tNode->lchild = rInsert(tNode->lchild, key);
    }
    else if(key > tNode->data){
        tNode->rchild = rInsert(tNode->rchild, key);
    }
    return tNode;
}

void Inorder(struct Node *temp){
    if(temp){
        Inorder(temp->lchild);
        printf("%d ", temp->data);
        Inorder(temp->rchild);
    }
}

struct Node * Search(int key){
    struct Node *temp = root;
    while(temp != NULL){
        if(key == temp->data){
            return temp;
        }
        else if(key < temp->data){
            temp = temp->lchild;
        }
        else{
            temp = temp->rchild;
        }
    }
    return NULL;
}

int Height(struct Node *tNode){
    int x, y;
    if(tNode == NULL){
        return 0;
    }
    x = Height(tNode->lchild);
    y = Height(tNode->rchild);
    return x>y?x+1:y+1;
}

struct Node *InPre(struct Node *tNode){
        while(tNode && tNode->rchild != NULL){
            tNode = tNode->rchild;
        }
        return tNode;
}

struct Node *InSucc(struct Node *tNode){
    while(tNode && tNode->lchild != NULL){
        tNode = tNode->lchild;
    }
    return tNode;
}

struct Node *Delete(struct Node *tNode, int key){
    struct Node *q;

    if(tNode == NULL){
        return NULL;
    }
    if((tNode->lchild == NULL) && (tNode->rchild == NULL)){
        if(tNode == root){
            root = NULL;
        }
        free(tNode);
        return NULL;
    }

    if(key < tNode->data){
        tNode->lchild = Delete(tNode->lchild, key);
    }
    else if(key > tNode->data){
        tNode->rchild = Delete(tNode->rchild, key);
    }
    else{
            if(Height(tNode->lchild) > Height(tNode->rchild)){
                    q = InPre(tNode->lchild);
                    tNode->data = q->data;
                    tNode->lchild = Delete(tNode->lchild, q->data);
            }
            else{
                    q = InSucc(tNode->rchild);
                    tNode->data = q->data;
                    tNode->rchild = Delete(tNode->rchild, q->data);
            }
    }
    return tNode;
}

int main()
{
    /*Insert(10);
    Insert(5);
    Insert(20);
    Insert(8);
    Insert(30);*/

    root = rInsert(root, 10);
    rInsert(root, 5);
    rInsert(root, 20);
    rInsert(root, 8);
    rInsert(root, 30);

    Delete(root, 20);

    Inorder(root);
    printf("\r\n");

    struct Node *temp;
    temp = Search(20);
    if(temp != NULL){
        printf("Element %d is found\r\n", temp->data);
    }
    else{
        printf("Element not found \r\n");
    }

    return 0;
}
