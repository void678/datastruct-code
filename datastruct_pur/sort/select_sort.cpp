#include<iostream>
#include"sortListHub.h"
using namespace std; 


//遍历一遍找到最小值，找到最小值对应的下标，将该值与该趟第一个数交换
void SelectSort(List &L){

    for(int i=0;i<L.length-1;i++){
        int k=i;
        for(int j=i+1;j<L.length;j++){
            if(L.elem[j]<L.elem[k]) k=j;
        }
        if(k!=i){
            int temp=L.elem[k];
            L.elem[k]=L.elem[i];
            L.elem[i]=temp;
        }

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

    SelectSort(L);
    ListTraverse(L);

}