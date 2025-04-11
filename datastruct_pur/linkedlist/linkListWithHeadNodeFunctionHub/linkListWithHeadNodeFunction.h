#include<iostream>
using namespace std;

typedef int ElemType;


typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;



//Function1:初始化链表
void InitList(LinkList &L){

    L=new LNode;
    L->next=NULL;  //头结点的next指针初始化为NULL

}

//头插法建立单链表
LinkList LinkedListCreateHeadInsert(LinkList &L){

    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;  //如果 p->next 为 NULL，则表示 p 指向的节点是链表的最后一个节点

    printf("输入节点数据(头插法): ");
    ElemType x;
    while((cin>>x)){
        LNode *p;
        p=new LNode;
        p->data=x;
        p->next=L->next;
        L->next=p;
    }
    return L;
}

void LinkedListCreateHeadInsert1(LinkList &L, int n) {

    printf("输入节点数据(头插法): ");
    for (int i = 0; i < n; i++) {
        LNode *p;
        p=new LNode;
        if (p == NULL) {
            exit(1); 
        }
        //printf("输入节点数据: ");
        cin>>p->data;
        p->next = L->next; 
        L->next=p;
        
    }
}



//尾插法建立单链表
LinkList LinkedListTailInsert1(LinkList &L){

    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;

    ElemType x;

    LNode *s,*p;
    p=L;
    printf("输入节点数据(尾插法):");
    while(cin>>x){
        LNode *s;
        s=new LNode;
        s->data=x;
        s->next=NULL;
        p->next=s;
        p=p->next;
    }

    return L;

}


void LinkedListTailInsert(LinkList &L, int n) {

    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;

    LNode *p;
    p=L;
    printf("输入节点数据(尾插法): ");
    for (int i = 0; i < n; i++) {
        LNode *s;
        s=new LNode;
        if (s == NULL) {
            exit(1); 
        }
       // printf("输入节点数据: ");
        cin>>s->data;
        s->next=NULL;
        p->next=s;
        p=p->next;    
    }
}




//Function2:摧毁该链表
void DestroyList(LinkList &L){

    LNode *p;
    while(L!=NULL){
        p=L->next;
        delete L;    //delete、free 只释放指针指向的内存，而不会改变指针本身的值
        L=p;
    }

}


//Function3：清空该链表
void ClearList(LinkList &L){

    LNode *p;
    while(L->next!=NULL){
        p=L->next;
        L->next=p->next;
        delete p;
    }
    L->data=0;

}



//Function 4 :判定是否为空链表
bool ListEmpty(LinkList L){

    if(L->next==NULL){
        return 1;
    }
    else return 0;

}


//Function 5:返回链表长度
int ListLength(LinkList L){

    if(L->next==NULL){
        return 0;
    }

    LNode *p;
    p=L->next;

    int cou=0;
    while(p!=NULL){
        cou++;
        p=p->next;
    }

    return cou;

}


//Function 6:返回第i个结点的元素值,并用e返回
void GetElem(LinkList L,int i,ElemType &e){


    if (L == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    LNode *p;
    p=L->next;
    int cou=1;
    while(p!=NULL&&cou<i){
        p=p->next;
        cou++;
    }
    // if(cou==i) e=p->data;
    // else cout<<"NULL";

     if (p != NULL) {
        e = p->data;
    } else {
        cout << "NULL" << endl;
    }

}



//Function7：返回元素e所在的位置
int LocateElem(LinkList L,ElemType e){

    LNode *p;
    p=L->next;
    int cou=1;
    while(p!=NULL&&p->data!=e){
        p=p->next;
        cou++;
    }
    if(p==NULL)
        return 0;
    if(p->data==e){
        return cou;
    }
    else return 0;

}


//Function8: 返回cur_e的直接前驱元素,并用pre_e返回
ElemType PriorELem(LinkList L,ElemType cur_e,ElemType &pre_e){

    LNode *p;
    p=L->next;
    while(p->next->data!=cur_e){
        p=p->next;
    }
    pre_e=p->data;
    return pre_e;

}



//Function9:返回cur_e的直接后驱元素,并用next_e返回
ElemType NextElem(LinkList L,ElemType cur_e,ElemType &next_e){

    LNode *p;
    p=L->next;
    while(p->data!=cur_e&&p->next!=NULL){
        p=p->next;
    }
    if(p->data==cur_e&&p->next==NULL){
        return 0;
    }
    next_e=p->next->data;
    return next_e;
}


//Function10:在第i个结点前/后插入元素e
void ListInsert(LinkList &L,int i,ElemType e){

    
    LNode *p;
    p=L->next;
    if(i==1){
        LNode *q=new LNode;
        q->data=e;
        q->next=p;
        L->next=q;
    }
    int cou=1;
    while(p!=NULL&&cou<i-1){
        p=p->next;
        cou++;
    }
    if(cou==i-1){
        LNode *q=new LNode;
        q->data=e;
        q->next=p->next;
        p->next=q;
    }
    return;

}


void ListInsert1(LinkList &L,int i,ElemType e){

    LNode *p;
    p=L->next;
    int cou=1;
    while(p!=NULL&&cou<i){
        p=p->next;
        cou++;
    }
    LNode *q=new LNode;
    q->data=e;
    q->next=p->next;
    p->next=q;

    return;

}


//Function11: 删除第i个结点,并用e返回其元素值
void ListDelete(LinkList &L,int i,ElemType &e){

    LNode *p;
    p=L->next;
    if(i==1){
        L->next=p->next;
        delete p;
        return;
    }

    int cou=1;
    
    while(p!=NULL&&cou<i-1){
        p=p->next;
        cou++;
    }
    LNode *q;
    q=p->next; 
    e=q->data;
    p->next=q->next;
    delete q;
    
    return;

}


// Function12: 输出链表中的所有元素
void ListTraverse(LinkList L) {
    LNode *p;
    p = L->next;
    
    while (p != NULL) {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout<<"NULL"<<endl;
}