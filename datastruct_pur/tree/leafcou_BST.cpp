//排序二叉树：叶子结点数目
#include<bits/stdc++.h>
using namespace std;

typedef char TElemType;

typedef struct BiLNode{
    struct BiLNode *lchild,*rchild;
    TElemType data;
}BiTNode,*BiTree;

BiTree T;
int sum;
int DLR(BiTree T){
    if(T!=NULL){
        if((T->lchild==NULL)&&(T->rchild)==NULL){
            sum++;
            printf("%d  ",T->data);
        }
        DLR(T->lchild);
        DLR(T->rchild);
    }
    return 0;
}

void insert_data(int x){
    BiLNode *p,*q,*s;
    s=new BiLNode;
    s->data=x,s->lchild=NULL,s->rchild=NULL;
    if(!T) {
        T=s;return;
    }
    p=T;
    while (p)
    {
        q=p;
        if(p->data<=x) p=p->rchild;
        else p=p->lchild;
    }
    if(q->data<=x) q->rchild=s;
    else q->lchild=s;

}

int main(){
    int i,x;
    i=1;
    T=NULL;
    do{
        printf("please input data%d :\n",i);
        i++;
        cin>>x;
        if(x==-9999){
            DLR(T);
            printf("count:%d",sum);
            return 0;
        }
        else insert_data(x);
    }while(x!=-9999);

    
    return 0; 
}