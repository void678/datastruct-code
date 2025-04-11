#include<iostream>

using namespace std; 


const int LIMS = 100;
const int LINC = 10;

typedef int ElemType;

typedef struct{

    ElemType *elem;
    int length;
    int listsize;
    int incrementsize;

}List;


//Function 1 : 构造一个空的线性表L
void InitList(List &L){

    L.elem=new ElemType[LIMS];  //L.elem=(ElemType *)malloc(LIMS*sizeof(ElemType));
    L.length=0;
    L.listsize=LIMS;
    L.incrementsize=LINC;

}

//Function 10:在L的第i个元素之前插入新的元素e，L的长度增1
bool ListInsert(List &L,int i,ElemType e){

    if(i<1||i>L.length+1||L.length>=L.listsize){                 //xy
        return false;
    }
    for(int k=L.length;k>=i;k--){
        L.elem[k]=L.elem[k-1];
    }
    L.elem[i-1]=e;
    L.length++;
    return true;

}

//Function 12: 依次输出L中的每个数据元素
void ListTraverse(List L){

    for(int i=0;i<L.length;i++){
        cout<<L.elem[i]<<" ";
    }
    cout<<endl;

}