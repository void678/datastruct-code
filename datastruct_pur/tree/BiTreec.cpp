#include<iostream>
using namespace std;

typedef char ElemType;


typedef struct BiTNode{
    char data;
    BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

typedef BiTNode* QElemType;

typedef struct{
    QElemType *elem;
    int queuesize;
    int front;
    int rear;
}Queue;

void Init_Q(Queue &Q,int elemnum){
    Q.elem=new QElemType[elemnum+1];
    Q.queuesize=elemnum+1;
    Q.front=Q.rear=0;
}

bool Empty_Q(Queue Q){
    if(Q.front==Q.rear) return 1;
    else return 0;
}

void Push_Q(Queue &Q,QElemType e){
    Q.elem[Q.rear]=e;
    Q.rear=(Q.rear+1)%Q.queuesize;
}

bool Pop_Q(Queue &Q,QElemType &e){
    if(Q.front==Q.rear) return 0;
    e=Q.elem[Q.front];
    Q.front=(Q.front+1)%Q.queuesize;
    return 1;
}


void visit(BiTNode* p){
    cout<<p->data;
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
    Queue Q;
    Init_Q(Q,100);

    BiTNode *p;
    p=T;
    Push_Q(Q,p);

    while(!Empty_Q(Q)){
        
        BiTNode *fa;
        Pop_Q(Q,fa);
        visit(fa);

        if(fa->lchild) Push_Q(Q,fa->lchild);
        if(fa->rchild) Push_Q(Q,fa->rchild);
    }
}


bool iscom(BiTree T){
    int flag=1;
    if(!T) return 1;
    BiTNode *p=T;
    Queue Q;
    Init_Q(Q,100);
    Push_Q(Q,p);
    

    while(!Empty_Q(Q)){
        BiTNode *fa;
        Pop_Q(Q,fa);
       
        if(fa==NULL) flag=0;
        else{
            if(!flag) return 0;
            Push_Q(Q,fa->lchild);
            Push_Q(Q,fa->rchild); 
        }    
    }
    return 1;
}



int main(){
    BiTree T=NULL;
    create_T(T);
    
    cout<<"层次遍历: ";
    levelorder(T,visit);
    cout<<endl;
    if(iscom(T)) cout<<"是完全二叉树"<<endl;
    else cout<<"不是完全二叉树"<<endl;
    return 0;

}