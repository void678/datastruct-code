#include<iostream>
#include"sortListHub.h"
using namespace std; 



//从第二个元素开始，将每个元素插入到已排序部分的正确位置
void InsertSort(List &L){
    
    for(int i=1;i<L.length;i++){
        int key=L.elem[i];
        int j=i-1;

        while(j>=0&&L.elem[j]>key){
            L.elem[j+1]=L.elem[j];
            j--;
        }
        L.elem[j+1]=key;
    }

}


int main(){

    List L;
    ElemType e;
    InitList(L);
    int n;
    printf("num=");
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>e;
        ListInsert(L,i,e);
    }
    
    InsertSort(L);
    ListTraverse(L);

}