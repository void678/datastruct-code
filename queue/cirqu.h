#include<iostream>
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

int Length_Q(Queue Q){
    return (Q.rear-Q.front+Q.queuesize)%Q.queuesize;
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

bool Head_Q(Queue Q,QElemType &e){
    if(Q.front==Q.rear) return 0;
    e=Q.elem[Q.front];
    return 1;
}

void Traverse_Q(Queue Q){
    if(Q.front==Q.rear) return;
    for(int i=Q.front;i!=Q.rear;i=(i+1)%Q.queuesize)
        cout<<Q.elem[i]<<" ";
    cout<<Q.elem[Q.rear];
}