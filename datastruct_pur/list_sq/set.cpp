#include<iostream>
#include"listFunctionHub.h"

using namespace std; 


//Function 2.1: 实现集合的并运算
void UnionList(List LC, List LD, List &LE) {
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
void MulList(List LC, List LD, List &LF) {
    int Lc_len = ListLength(LC);
    int Lf_len = ListLength(LF);
    ElemType e = 0;
    for (int i = 1; i <= Lc_len; ++i) {
        GetElem(LC, i, e);
        if (LocateElem(LD, e)) {
            ListInsert(LF, ++Lf_len, e);
        }
    }
    ListTraverse(LF);
}


//Function 2.3: 实现集合的减运算
void  SubList(List LC, List LD, List &LG) {
    int Lc_len = ListLength(LC);
    ElemType e = 0;
    for (int i = 1; i <= Lc_len; ++i) {
        GetElem(LC, i, e);
        ListInsert(LG, i, e);
    }

    int Lg_len = ListLength(LG);
    for (int i = 1; i <= Lg_len; ++i) {
        GetElem(LC, i, e);
        if (LocateElem(LD, e)) {
            ListDelete(LG, LocateElem(LG, e), e);
        }
    }
    ListTraverse(LG);
}


//Function 2.4: 实现集合的去重操作
void PurgeList(List LC,List &LH,List &LI){


    int Lc_len = ListLength(LC);
    
    for (int i = 1; i <= Lc_len; ++i) {
        ElemType e ;
        GetElem(LC, i, e);
        ListInsert(LH, i, e);
    }
    
    ElemType e;
    int Lh_len=ListLength(LH);
    int Li_len=ListLength(LI);

    while(!ListEmpty(LH)){
        ListDelete(LH,1,e);
        if(!LocateElem(LI,e)) ListInsert(LI,++Li_len,e);
    }
    DestroyList(LH);
    ListTraverse(LI);

}



//Function 2.5:判别两个集合是否相等
bool IsequalList(List La,List Lb){

    int AL=La.length;
    int BL=Lb.length;
    if(AL!=BL){
        printf("not equal\n");
        return 0;
    }
    List Lc;
    InitList(Lc);
    ElemType e;
    for(int k=1;k<=AL;k++){
        GetElem(La,k,e);
        ListInsert(Lc,k,e);
    }
    ListTraverse(Lc);
    for(int i=1;i<=BL;i++){
        GetElem(Lb,i,e);
        int cou=LocateElem(Lc,e);
        if(cou==0) {
            printf("not equal\n");
            return 0;
        }
        else ListDelete(Lc,cou,e);
    }
    if(ListEmpty(Lc)) {
        printf("equal\n");
        return 1;
    }
    else {
        printf("not equal\n");
        return 0;
    }
    DestroyList(Lc);

}


//Function 2.5:实现对两个顺序表的比较/对两表中"位序相同"的元素进行比较
int CompareList(List La,List Lb){

    int k=0;
    while(k<La.length&&k<Lb.length){
        if(La.elem[k]>Lb.elem[k]) return 1;
        else if(La.elem[k]<Lb.elem[k]) return -1;
        else k++;
    }
    if(La.length==Lb.length) return 0;
    else if(La.length>Lb.length) return 1;
    else return -1;

}




int main(){


    List LA,LB,LC,LD,LE,LF,LG,LH;
    ElemType e;
    int al,bl;
    InitList(LA);
    InitList(LB);
    InitList(LC);
    InitList(LD);
    InitList(LE);
    InitList(LF);
    InitList(LG);
    InitList(LH);

    
    
    printf("*************************Input LA********************\n");
    cout<<"num = ";
    cin>>al;
    cout<<"elem = ";
    for(int i=1;i<=al;i++){
        cin>>e;
        ListInsert(LA,i,e);
    }


    printf("*************************Input LB********************\n");
    cout<<"num = ";
    cin>>bl;
    cout<<"elem = ";
    for(int i=1;i<=bl;i++){
        cin>>e;
        ListInsert(LB,i,e);
    }
    


    printf("*************************Result***********************\n");

    printf("LA = ");
    ListTraverse(LA);

    printf("LB = ");
    ListTraverse(LB);



    printf("LA U LB = ");
    UnionList(LA,LB,LC);
    
    printf("LA * LB = ");
    MulList(LA,LB,LD);
    
    printf("LA - LB = ");
    SubList(LA,LB,LE);
       
    printf("LB - LA = ");   
    SubList(LB,LA,LF);
    
    // printf("LA -- =");
    // PurgeList(LA,LG,LH);

    // IsequalList(LA,LB);

    // if(CompareList(LA,LB)==1) printf("LA > LB\n");
    // else if(CompareList(LA,LB)==0) printf("LA = LB\n");
    // else printf("LA < LB\n");

}