#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *lchild;
    struct Node *rchild;
    int data;
}*root = NULL;

struct Stack{
    int size;
    int top;
    int *S;
}*stk = NULL;

void Push(struct Stack *st, int value){
    if(st->top == st->size-1){
        printf("Stack overflow \r\n");
    }
    else{
        st->top++;
        st->S[st->top] = value;
    }
}

int Pop(struct Stack *st){
    int deleted = -1;
    if(st->top == -1){
        printf("Stack underflow \r\n");
    }
    else{
        deleted = st->S[st->top--];
        free(st->S[st->top--]);
    }
    return deleted;
}

void createPre(int pre[], int size){
    int i=0;
    struct Node *tNode;
    struct Node *nNode;

    stk->size = size;
    stk->top = -1;
    stk->S = (int*)malloc(stk->size * sizeof(int));

    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = pre[i++];
    root->lchild = root->rchild = NULL;
    tNode = root;

    while(i < size){
            if(pre[i] > tNode->data){
                nNode = (struct Node *)malloc(sizeof(struct Node));
                nNode->data = pre[i++];
                nNode->lchild = nNode->rchild = NULL;
                tNode->lchild = nNode;
                Push(&stk, tNode);
                tNode = nNode;
            }
            else{
                if((pre[i] > tNode->data) && (pre[i] < stk->S[stk->top])){
                        nNode = (struct Node *)malloc(sizeof(struct Node));
                        nNode->data = pre[i++];
                        nNode->lchild = nNode->rchild = NULL;
                        tNode->lchild = nNode;
                        tNode = nNode;
                }
                else{
                    tNode = Pop(&stk);
                }
            }
    }
}

void Preorder(struct Node *tNode){
    if(tNode){
        printf("%d ", tNode->data);
        Preorder(tNode->lchild);
        Preorder(tNode->rchild);
    }
}

int main()
{
    int A[] = {1,2,3,4,5};
    int size = sizeof(A) / sizeof(int);
    createPre(A, size);

    Preorder(root);

    return 0;
}
