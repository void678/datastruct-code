#include<iostream>
#include<vector>
using namespace std;


void swap(int &x,int &y){
    int t=x;
    x=y;
    y=t;
}
void sift_down(vector<int> &a,int start,int end){
    int parent=start;
    int child=parent*2+1;
    while(child<=end){
        if(child+1<=end&&a[child]<a[child+1]) child++;
        if(a[parent]>a[child]) return;
        else {
            swap(a[parent],a[child]);
            parent=child;
            child=parent*2+1;
        }
    }
}

void heap_sort(vector<int> &a){

    int len=a.size();
    //从最后一个节点的父节点开始sift down以完成堆化(heapify)
    for(int i=(len-1-1)/2;i>=0;i--)
        sift_down(a,i,len-1);

    for(int i=len-1;i>0;i--){
        swap(a[0],a[i]);
        sift_down(a,0,i-1);
    }
    
}

int main(){

    int n;
    cin>>n;
    
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    heap_sort(a);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;

    return 0;
}
