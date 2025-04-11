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


//Function 2: 销毁线性表L
void DestroyList(List &L){

    delete[] L.elem;
    L.length=0;
    L.listsize=0;

}


// Function 3: 将L重置为空表
void ClearList(List &L){

    L.length=0;

}


//Function 4: 若L为空表，则返回TRUE;否则FALSE
bool ListEmpty(List L){

    return L.length==0;

}


//Function 5: 返回L中元素个数，即线性表L的个数
int ListLength(List L){

    return L.length;

}


//Function 6: 用e返回L中第i个元素的值
void GetElem(List L,int i,ElemType &e){

    if(i<1||i>L.length) return;
    e=L.elem[i-1];
    return;

}


//Function 7: 返回L中第1个其值与e相等的元素的位序。若这样的元素不存在，则返回值为0
int LocateElem(List L,ElemType e){

    int i=0;
    for(i=0;i<L.length;i++){
        if(L.elem[i]==e) break;
    }
    if(i==L.length){
        return 0;
    }
    return i+1;                   //xy

}


//Function 8: 若cur_e是L的元素，但不是第一个，则用pre_e返回它的前驱；否则操作失败，pre_e无定义
int PriorElem(List L,ElemType cur_e,ElemType &pre_e){

    int k=LocateElem(L,cur_e);
    if(k==0){
        //cout<<cur_e<<"不是L中的元素"<<endl;
        return 0;
    }
    if(k==1){
        //cout<<cur_e<<"是L中的第1个元素,并无直接前驱"<<endl;
        return 0;
    }
    pre_e=L.elem[k-2];
    return pre_e;
}


//Function 9: 若cur_e是L的元素，但不是最后一个，则用next_e返回他的后继；否则操作失败，next_e无定义
int NextElem(List L,ElemType cur_e,ElemType &next_e){

    int k=LocateElem(L,cur_e);
    if(k==0){
        //cout<<cur_e<<"不是L中的元素"<<endl;
        return 0;
    }
    if(k==L.length){
        //cout<<cur_e<<"是L中的第1个元素,并无直接前驱"<<endl;
        return 0;
    }
    next_e=L.elem[k-2];
    return next_e;

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




//Function 10:在L的第i个元素之前插入新的元素e，L的长度增1
void increment(List &L){
	ElemType *a;   //ElemType a[];
	a=new ElemType[L.listsize+L.incrementsize];
	for(int i=0;i<L.length;i++){
		a[i]=L.elem[i];
	}
	delete[] L.elem;  //free(L.elem);
	L.elem=a;
	L.listsize+=L.incrementsize;
}
void ListInsert1(List &L,int i,ElemType e){
	if(i<1||i>L.length+1){
		//cout<<"i值不合法"<<endl;
		return;
	}
	ElemType *q,*p;
	if(L.length>=L.listsize) increment(L);
	q=&L.elem[i-1];
	for(p=&L.elem[L.length-1];p>=q;--p){
		*(p+1)=*p;
	}
	*q=e;
	L.length++;
}


//Function 11:删除L的第i个元素，并用e返回其值，L的长度减1
void ListDelete(List &L,int i,ElemType &e){

    if(i<1||i>L.length) return;
    e=L.elem[i-1];
    for(int k=i;k<L.length;k++){
        L.elem[k-1]=L.elem[k];
    }
    L.length--;
    return;

}


void ListDelete1(List &L,int i,ElemType &e){

    if(i<1||i>L.length) return;
    ElemType *p,*q;
    p=&L.elem[i-1];
    e=*p;
    q=L.elem+L.length-1;
    for(++p;p<=q;p++){
        *(p-1)=*p;
    }
    L.length--;

}


void ListDelete2(List &L,int i,ElemType &e){

    if(i<1||i>L.length) return;
    e=L.elem[i-1];
    memcpy(L.elem+i-1,L.elem+i,(L.length-i)*sizeof(ElemType));

}



//Function 12: 依次输出L中的每个数据元素
void ListTraverse(List L){

    for(int i=0;i<L.length;i++){
        cout<<L.elem[i]<<" ";
    }
    cout<<endl;

}
