#include<bits/stdc++.h>

using namespace std;

const int STACK_INIT_SIZE = 100;
const int STACKINCREMENT = 10;

typedef int SElemType;
typedef struct {
    SElemType *elem;
    int top; 
    int stacksize;
    int incrementsize; 
} SqStack;


void InitStack(SqStack &S) {
    S.elem = new SElemType[STACK_INIT_SIZE];
    S.top = -1;
    S.stacksize = STACK_INIT_SIZE;
    S.incrementsize = STACKINCREMENT;
}

bool StackEmpty(SqStack S) {
    if (S.top == -1) {
        return true;
    } else {
        return false;
    }
}

bool Push(SqStack &S, SElemType e) {
    if (S.top == STACK_INIT_SIZE - 1) {
        return false;
    }
    S.elem[++S.top] = e;
    return true;
}

bool GetTop(SqStack S, SElemType &e) {
    if (S.top == -1) {
        return false;
    }
    e = S.elem[S.top];
    return true;
}

bool Pop(SqStack &S, SElemType &e) {
    if (S.top == -1) {
        return false;
    }
    e = S.elem[S.top--];
    return true;
}

bool StackTraverse(SqStack S) {
    if (S.top == -1) {
        return false;
    }

    cout<<"找到一组解(物品的序号):";

    while (S.top != -1) {
        int e = 0;
        Pop(S, e);
        
        cout << e+1 << " ";
    }
    cout<<endl;
    return true;
}


SqStack s;

void knapsack(int w[],int T,int n){

    int k=0;
    do{
        while(T>0&&k<n){
            if(T-w[k]>=0){
                Push(s,k);
                T-=w[k];
            }
            k++;
        }
        if(T==0) StackTraverse(s);
        GetTop(s,k);
        Pop(s,k);
        T+=w[k];
        k++;
        
    }while(!StackEmpty(s)||k<n); 
}

int main(){

    InitStack(s);

    int T,n;
    printf("请输入物品个数：");
    cin>>n;
    
    int w[n];
    printf("请输入每个物品的体积:\n");
    for(int i=0;i<n;i++){
        printf("第%d个物品的体积 = ",i+1);
        cin>>w[i];
    }
    printf("请输入背包体积 T = ");
    cin>>T;
    knapsack(w,T,n);

}