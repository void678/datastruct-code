#include<iostream>
#include"sortListHub.h"
using namespace std; 



//交换相邻的元素来将大的元素“冒泡”到数组的末尾
void BubbleSort(List &L){
    
    for(int i=0;i<L.length-1;i++){
        int flag=0;
        for(int j=0;j<L.length-i-1;j++){
            if(L.elem[j]>L.elem[j+1]){
                int temp=L.elem[j];
                L.elem[j]=L.elem[j+1];
                L.elem[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0) break;
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
    
    BubbleSort(L);
    ListTraverse(L);

}