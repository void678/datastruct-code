#include<bits/stdc++.h>
using namespace std;
typedef struct
{
    int weight;
    int parent,lchild,rchild;
}HTNode,* HuffmanTree;

typedef char** HuffmanCode;

void Select(HuffmanTree HT,int n,int& s1,int& s2)
{
    int min1=9999,min2=9999;
    for(int i=1;i<=n;i++){
        if(HT[i].parent==0&&HT[i].weight<min1){
            min1=HT[i].weight;
            s1=i;
        }
    }
    for(int i=1;i<=n;i++){
        if(HT[i].parent==0&&i!=s1&&HT[i].weight<min2){
            min2=HT[i].weight;
            s2=i;
        }
    }
}

void HuffmanCoding(HuffmanTree& HT,HuffmanCode& HC,int* w,int n)
{
    if(n<=1)
        return;
    int m=2*n-1;
    HT=new HTNode[m+1];
    int i;
    for(i=1;i<=n;i++,w++){
        HT[i].parent=HT[i].lchild=HT[i].rchild=0;
        HT[i].weight=*w;
    }
    for(;i<=m;i++){
        HT[i].parent=HT[i].lchild=HT[i].rchild=HT[i].weight=0;
    }
    
    int s1,s2;
    for(i=n+1;i<=m;i++){
        Select(HT,i-1,s1,s2);
        HT[i].lchild=s1;
        HT[i].rchild=s2;
        HT[s1].parent=HT[s2].parent=i;
        HT[i].weight=HT[s1].weight+HT[s2].weight;
    }
   
    HC=new char*[n+1];
    char* ch=new char[n];
    int chlen=0;
    int p=m;
    for(int i=1;i<=m;i++)
        HT[i].weight=0;
    while(p){
        if(HT[p].weight==0){
            HT[p].weight=1;
            if(HT[p].lchild!=0){
                p=HT[p].lchild;
                ch[chlen++]='0';
            }
            else if(HT[p].rchild==0){
                HC[p]=new char[chlen+1];
                ch[chlen]='\0';
                strcpy(HC[p],ch);
            }
        }
        else if(HT[p].weight==1){
            HT[p].weight=2;
            if(HT[p].rchild!=0){
                p=HT[p].rchild;
                ch[chlen++]='1';
            }
        }
        else{
            HT[p].weight=0;
            p=HT[p].parent;
            chlen--;
        }
    }
    delete ch;
}

void Output_HuffmanCode(HuffmanCode HC,int n,char *s)
{
    cout<<"----"<<endl;
    for(int i=1;i<=n;i++){
        cout<<s[i-1]<<":";
        for(int j=0;HC[i][j]!='\0';j++)
            cout<<HC[i][j];
        cout<<endl;
    }
    cout<<"\n----"<<endl;
}

int main()
{
    HuffmanTree HT;
    HuffmanCode HC;
    int n;
    printf("------------------Input----------------\n");
    printf("请输入哈夫曼树中叶子结点的个数：");
    scanf("%d",&n);
    getchar();
    int *w=new int[n];
    char *s=new char[n];
    printf("请输入各个叶子结点的编码和权重:\n");
    printf("\n");
    for (int i = 0; i < n; ++i) {
        printf("第%d个编码: ",i+1);
        scanf("%c",&s[i]);
        getchar();
        printf("其权值为: ");
        scanf("%d", &w[i]);
        getchar();
    }
   
    HuffmanCoding(HT,HC,w,n);
    Output_HuffmanCode(HC,n,s);
    return 0;
}