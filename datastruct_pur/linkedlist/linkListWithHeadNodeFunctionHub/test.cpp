#include<iostream>
#include"linkListWithHeadNodeFunction.h"
using namespace std;

void DelMax(LinkList &L){
    LNode *p=L->next,*q,*max;
    int maxkey;
    max=p;
    q=p->next;
    while(q){
        if(max->data<q->data) max=q;
        q=q->next;
    }
        maxkey=p->data;
        while(p!=NULL){
            if(p->next&&p->next->data>maxkey)
                maxkey=p->next->data;
            p=p->next;
        }
    maxkey=max->data;
    cout<<maxkey<<endl;
}


// void DelMaxNodes(LinkList &L)
// {
//  linkNode *pre = L, *p = L->next;
//  max = p->data;
//  while(p != NULL) //找到链表中最大值==>max
//  {
// if (p->data > max) max = p->data;
// p = p->next;
//  }
//  p = L->next;
//  while(p != NULL) //查找等于 max 的节点并删除
//  {
// if (p->data == max) //删除该结点
// {
//  pre->next = p->next;
//  free(p);
//  p = pre->next; //让 p 继续指向 pre 结点的后继结点
// }
//  else
// {
//  pre = p; //pre、p 指针同步后移
//  p = p->next;
// }
//  }
// }


//     p=L->next,q=p->next;
//     if(p->data==maxkey){
//         L->next=p->next;
//         free(p);
//     }
//     while(p->next!=NULL){
//         if(p->next->data==maxkey){
//             q=p->next;
//             p->next=q->next;
//             free(q);
//         }
//         p=p->next;
//     }
// }

int main(){

    LinkList LA,LB,LC,LD,LE,LF;
    InitList(LA);
    

    int la_len;
    ElemType e;

    printf("********************Input L********************\n");
    printf("num = ");
    cin>>la_len;
    LinkedListTailInsert(LA,la_len);


    cout<<"LA = ";
    ListTraverse(LA);
   
    DelMax(LA);
    // cout<<"After Delete:"<<endl;

    ListTraverse(LA);
   


    return 0;
    

}