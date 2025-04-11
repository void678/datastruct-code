#include<iostream>
#include<string.h>
using namespace std;

typedef int QElemType;

typedef struct{
    QElemType *elem;
    int front;
    int rear;
    int queuesize;
}Queue;


void Init_Q(Queue &Q,int elemnum){
    Q.elem=new QElemType[elemnum+1];
    Q.front=Q.rear=0;
    Q.queuesize=elemnum+1;
}

bool Empty_Q(Queue Q){
    if(Q.front==Q.rear) return 1;
    return 0;
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

void Head_Q(Queue Q,QElemType &e){
    if(Q.front==Q.rear) return;
    e=Q.elem[Q.front];
}
void yanghui(int n){
   
    for(int i=1;i<=n;i++) cout<<" ";
    cout<<1<<endl;

    Queue Q;
    Init_Q(Q,100);

    Push_Q(Q,0);
    Push_Q(Q,1);
    Push_Q(Q,1);

    int k=1,e=0,s;

    while (k<n)
    {
        for(int i=1;i<=n-k;i++) cout<<" ";
        Push_Q(Q,0);
        do{
            Pop_Q(Q,s);
            Head_Q(Q,e);
            if(e) cout<<e<<" ";
            else cout<<endl;
            Push_Q(Q,s+e);
        }while (e!=0);
        k++;    
    }
    Pop_Q(Q,e);
    while(!Empty_Q(Q)){
        Pop_Q(Q,e);
        cout<<e<<" ";
    }
}
int main(){
    
    int x;
    cin>>x;
    yanghui(x);
    return 0;
}