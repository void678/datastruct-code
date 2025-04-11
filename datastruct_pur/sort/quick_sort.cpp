#include<iostream>
#include"sortListHub.h"
using namespace std; 



/*从数列中挑出一个元素，称为 "基准"（pivot）;

重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。在这个分区退出之后，该基准就处于数列的中间位置。这个称为分区（partition）操作；

递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序；*/
int Partition(List &L,int low,int high){
    
    int pivot=L.elem[low];
    ElemType pivotkey = L.elem[low];
    while(low<high){
        while(low<high&&L.elem[high]>=pivotkey) --high;
        if(low<high) L.elem[low++]=L.elem[high];
        while(low<high&&L.elem[low]<=pivotkey) ++low;
        if(low<high) L.elem[high--]=L.elem[low];
    }
    L.elem[low]=pivot;
    return low;

}


void Qsort(List &L,int s,int t){
    int pivotloc;
    if(s<t){
        pivotloc=Partition(L,s,t);
        Qsort(L,s,pivotloc-1);
        Qsort(L,pivotloc+1,t);
    }
}

void QuickSort(List &L){
    Qsort(L,0,L.length-1);
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
    
    QuickSort(L);
    ListTraverse(L);

}