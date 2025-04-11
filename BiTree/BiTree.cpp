#include<iostream>
#include<queue>
using namespace std;

typedef char ElemType;

typedef struct BiTNode{
    char data;
    BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void visit(BiTNode* p){
    cout<<p->data<<" ";
}

void preorder(BiTree T,void(*visit)(BiTree)){
    if(!T) return;
    visit(T);
    if(T->lchild) preorder(T->lchild,visit);
    if(T->rchild) preorder(T->rchild,visit);
    return;
}

void inorder(BiTree T,void(*visit)(BiTree)){
    if(!T) return;
    if(T->lchild) inorder(T->lchild,visit);
    visit(T);
    if(T->rchild) inorder(T->rchild,visit);
}


void postorder(BiTree T,void(*visit)(BiTree)){
    if(!T) return;
    if(T->lchild) postorder(T->lchild,visit);
    if(T->rchild) postorder(T->rchild,visit);
    visit(T);
}

void create_T(BiTree &T){
    char ch;
    cin>>ch;
    if(ch=='#') T=NULL;
    else{
        T=new BiTNode;
        T->data=ch;
        create_T(T->lchild);
        create_T(T->rchild);
    }
}

void levelorder(BiTree T,void(*visit)(BiTree)){
    if(!T) return;
    queue<BiTNode*> q;
    BiTNode *p;

    p=T;
    q.push(p);
    while(!q.empty()){
        
        BiTNode *fa=q.front();
        q.pop();
        visit(fa);
        if(fa->lchild) q.push(fa->lchild);
        if(fa->rchild) q.push(fa->rchild);
    }
}


bool iscom(BiTree T){
    int flag=1;
    if(!T) return 1;
    BiTNode *p=T;
    queue<BiTNode *> q;
    q.push(p);
    

    while(!q.empty()){
        BiTNode *fa=q.front();
        q.pop();
       
        if(fa==NULL) flag=0;
        else{
            if(!flag) return 0;
            q.push(fa->lchild);
            q.push(fa->rchild); 
        }
        
    }
    return 1;

}

void dep(BiTree T,int h,int &depth){
    if(T){
        if(h>depth) depth=h;
        dep(T->lchild,h+1,depth);
        dep(T->rchild,h+1,depth);
    }
}

//ABDH###E##CF##G##

int main(){
    BiTree T=NULL;
    cout << "先序创建二叉树 ";
    create_T(T);
    
    cout << "先序遍历: ";
    preorder(T,visit);
    cout<<endl;

    cout << "中序遍历: ";
    inorder(T,visit);
    cout<<endl;

    cout << "后序遍历: ";
    postorder(T,visit);
    cout<<endl;

    cout << "层次遍历: ";
    levelorder(T,visit);
    cout<<endl;

    if(iscom(T)) cout<<"是完全二叉树"<<endl;
    else cout<<"不是完全二叉树"<<endl;

    int depth=0;
    dep(T,1,depth);
    cout<<"深度d="<<depth<<endl;

    return 0;

}