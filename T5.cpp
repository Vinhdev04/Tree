#include"stdio.h"
#include"stdlib.h"


typedef struct Node{
    int data;
    struct Node *pLeft;
    struct Node *pRight;
}Node,*PtrNode;

void Init(PtrNode &t){
    t = NULL;
}

void Insert(PtrNode &t,int x){
    if(t==NULL){
        PtrNode p = new Node;
        p->data = x;
        p->pLeft = NULL;
        p->pRight = NULL;
        t = p;
    }else{
        if(t->data>x)
            Insert(t->pLeft,x);
        else if(t->data<x)
            Insert(t->pRight,x);
    }        
}

void PreOder(PtrNode t){
    if(t != NULL){
        printf("%d",t->data);
        PreOder(t->pLeft);
        PreOder(t->pRight);
    }
}

int main(){
    PtrNode t;
    Init(t);

    int x;
    printf("\nNhap x = ");
    scanf("%d",&x);
    Insert(t,x);
    printf("\nDUYET CAY THEO PreOder(NLR): \n");
    PreOder(t);
    return 0;
}