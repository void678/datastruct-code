#include<iostream>
#include"linkListWithHeadNodeFunction.h"

using namespace std;



//Function 2.1: 实现集合的并运算
void UnionList(LinkList LC, LinkList LD, LinkList &LE) {

    int Lc_len = ListLength(LC);
    
    for (int i = 1; i <= Lc_len; ++i) {
        ElemType e ;
        GetElem(LC, i, e);
        ListInsert(LE, i, e);
    }
    int Ld_len = ListLength(LD);
    int Le_len = ListLength(LE);
    for (int i = 1; i <= Ld_len; ++i) {
        ElemType e ;
        GetElem(LD, i, e);
        if (LocateElem(LE, e)) {
            continue;
        } else {
            ListInsert(LE, ++Le_len, e);
        }
    }
    ListTraverse(LE);

} 



//Function 2.2: 实现集合的交运算
void MulList(LinkList LC, LinkList LD, LinkList &LE) {
    int Lc_len = ListLength(LC);
    int Le_len = ListLength(LE);
    ElemType e = 0;
    for (int i = 1; i <= Lc_len; ++i) {
        GetElem(LC, i, e);
        if (LocateElem(LD, e)) {
            ListInsert(LE, ++Le_len, e);
        }
    }
    ListTraverse(LE);
}



//Function 2.3: 实现集合的减运算


//      LC/LE:2 3 5 6     LD:1 2 3 4
void  SubList(LinkList LC, LinkList LD, LinkList &LE) {
    int Lc_len = ListLength(LC);
    ElemType e;
    for (int i = 1; i <= Lc_len; ++i) {
        GetElem(LC, i, e);
        ListInsert(LE, i, e);
    }
    //ListTraverse(LE);
    int Le_len = ListLength(LE);
    for (int i = 1; i <= Le_len; ++i) {
        GetElem(LC, i, e);
        //cout<<"Get e "<<e<<endl;
        if (LocateElem(LD, e)) {
           // cout<<"e="<<e<<" "<<"Locate e "<<LocateElem(LE, e)<<" i="<<i<<endl;
            ListDelete(LE, LocateElem(LE, e), e);
            //cout<<"del"<<endl;
            //ListTraverse(LE);
        }
        //else continue;
    }
    ListTraverse(LE);
}



int main(){

    LinkList LA,LB,LC,LD,LE,LF;
    //InitList(LA);
   // InitList(LB);
    InitList(LC);
    InitList(LD);
    InitList(LE);
    InitList(LF);



    int la_len,lb_len;
    ElemType e;



    printf("********************Input LA********************\n");
    printf("num = ");
    cin>>la_len;
    LinkedListTailInsert(LA,la_len);

    printf("********************Input LB********************\n");
    printf("num = ");
    cin>>lb_len;
    LinkedListTailInsert(LB,lb_len);


    printf("******************** Result ********************\n");


    cout<<"LA = ";
    ListTraverse(LA);
    cout<<"LB = ";
    ListTraverse(LB);


    cout<<"LA U LB = ";
    UnionList(LA, LB, LC);

    cout<<"LA * LB = ";
    MulList(LA,LB,LD);

    cout<<"A - B = ";
    SubList(LA,LB,LE);

    cout<<"B - A = ";
    SubList(LB,LA,LF);


    return 0;
    

}