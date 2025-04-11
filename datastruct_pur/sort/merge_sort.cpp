#include<iostream>
using namespace std;

typedef char ElemType;

//分而治之
void merge(ElemType a[],int la_len,ElemType b[],int lb_len,ElemType c[]){

    int i=0,j=0,k=0;
    while(i<la_len&&j<lb_len){
        if(a[i]<b[j])
            c[k++]=a[i++];
        else c[k++]=b[j++];
    }
    while(i<la_len) c[k++]=a[i++];
    while(j<lb_len) c[k++]=b[j++];
}

void merge_sort(ElemType a[],int l,int r){
    if(l+1>=r) return;
    int mid=l+((r-l)>>1);
    merge_sort(a,l,mid);
    merge_sort(a,mid,r);
    ElemType tmp[1024]={};
    merge(a+l,mid-l,a+mid,r-mid,tmp+l);
    for(int i=l;i<r;i++) 
        a[i]=tmp[i];
}


int main(){

    //ElemType a[10]={89,75,56,78,45,69,25,98,56,12};
    ElemType a[10]={'a','c','b','h','k','y','i','t','p','w'};

    merge_sort(a,0,10);
    for(int i=0;i<10;i++){
        cout<<a[i]<<" ";
    }
}