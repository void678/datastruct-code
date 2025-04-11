#include<iostream>
using namespace std;

typedef int ElemType;

typedef struct BiLNode{
    ElemType data;
    BiLNode *lchild,*rchild;
}BiLNode,*BiTree;

bool search_BST(BiTree T,BiLNode* &p,BiLNode* &f,ElemType kval){

    if(!T) return 0;
    p=T;f=NULL;
    while(p){
        if(p->data==kval) return 1;
        else if(p->data>kval){
            f=p;p=p->lchild;
        }
        else {f=p;p=p->rchild;}
    }
    return 0;

}

bool Insert_BST(BiTree &T,ElemType kval){
    BiLNode *s=new BiLNode;
    BiLNode *q,*fa;
    s->data=kval,s->lchild=NULL,s->rchild=NULL;
    if(!T){
        T=s;
        return 1;
    }
    if(search_BST(T,q,fa,kval)) return 0;
    BiLNode *p=T;
    while(p){
        if(p->data>kval){
            if(p->lchild) p=p->lchild;
            else {p->lchild=s;break;}
        }
        else{
            if(p->rchild) p=p->rchild;
            else {p->rchild=s;break;}
        }
    }
    return 1;
}

void Del_BST(BiTree &T,ElemType kval){
    BiLNode *p,*fa,*s,*q;
    if(!search_BST(T,p,fa,kval)) return;
    if(p->lchild&&p->rchild){
        q=p,s=p->lchild;
        while(s->rchild){
            q=s;s=s->rchild;
        }
        p->data=s->data;
        if(q!=p) q->rchild=s->lchild;
        else q->lchild=s->lchild;
        delete s;
    }
    else{
        if(!p->rchild) {q=p;p=p->lchild;}
        else {q=p;p=p->rchild;}
        if(!fa) T=p;
        else if(q==fa->lchild) fa->lchild=p;
        else fa->rchild=p;
        delete q;
    }
    return;
}

void visit(BiLNode *p){
    cout<<p->data<<" ";
}

void Inorder(BiTree T,void(*visit)(BiTree)){
    if(!T) return;
    if(T->lchild) Inorder(T->lchild,visit);
    visit(T);
    if(T->rchild) Inorder(T->rchild,visit);
    return;
}

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

bool issort(BiTree T){
    int last=-9999,flag=1;
    if(T==NULL) return flag;

    if(T->lchild&&flag)
        issort(T->lchild);

    if(T->data<last) flag=0;
    last=T->data;

    if(T->rchild&&flag)
        issort(T->rchild);
    
    return flag;
}

int main(){
    BiTree T=NULL;
    int n;
    ElemType x;

    // cout<<"num = ";
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     cin>>x;
    //     Insert_BST(T,x);
    // }

    cin>>x;
    while(x!=-9999){
        Insert_BST(T,x);
        cin>>x;
    }
    Inorder(T,visit);

    cout<<"\ninsert x:\n";
    cin>>x;
    Insert_BST(T,x);
    Inorder(T,visit);

    cout<<"\ndel x:\n";
    cin>>x;
    Del_BST(T,x);
    Inorder(T,visit);

    if(issort(T)) cout<<"\n是二叉排序树\n";
    else cout<<"\n不是二叉排序树\n";

    cout<<"叶子节点：";
    DLR(T);
    cout<<"叶子节点数目：";
    cout<<sum<<endl;

}