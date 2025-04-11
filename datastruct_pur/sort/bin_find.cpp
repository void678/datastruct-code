#include<iostream>
using namespace std;
#define Max_Size 100

typedef struct{
    int key;
}ElemType;

typedef struct{
    ElemType *elem;
    int length;
    int tablesize;
}SSTable;

void Init_ST(SSTable &ST){
    ST.elem=new ElemType[Max_Size];
    ST.length=0;
    ST.tablesize=Max_Size;
}
//l:5
//0 1 2 3 4
//8 7 5 9 3
//i=2
//8 0 7 5 9 3

bool Insert_ST(SSTable &ST,int i,int key){
    if(i<1||i>ST.length+1||ST.length>=ST.tablesize) return 0;
    for(int k=ST.length;k>=i;k--){
        ST.elem[k].key=ST.elem[k-1].key;
    }
    ST.elem[i-1].key=key;
    
    ST.length++;
    return 1;
}


void Traverse_ST(SSTable ST){
    for(int i=0;i<ST.length;i++){
        cout<<ST.elem[i].key<<" ";
    }
    cout<<endl;
}


int bin_find(SSTable ST,int kval){
    int low=0,high=ST.length-1;
    while (low<=high)
    {
        int mid=(low+high)/2;
        if(kval==ST.elem[mid].key) return mid;
        else if(kval>ST.elem[mid].key) low=mid+1;
        else high=mid-1;     
    }
    return -1;
}

int main(){
    SSTable ST;
    Init_ST(ST);
    int n,key,x;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        Insert_ST(ST,i,x);
    }
    
    Traverse_ST(ST);

    cin>>key;
    if(bin_find(ST,key)==-1){
        cout<<"not found"<<endl;
    }
    else cout<<bin_find(ST,key)+1<<endl;

}