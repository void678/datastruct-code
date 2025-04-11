#include <bits/stdc++.h>
using namespace std;
#define OVERFLOW -2 //内存溢出错误常量
#define OK 1        
#define ERROR 0    
#define TRUE 1      
#define FALSE 0    

typedef int Status; //指定状态码的类型是int
#define INFINITY 65535
#define MAX_VERTEX_NUM 20

typedef enum{
  //（有向图=0，有向网=1，无向图=2，无向网=3）
    DG,
    DN,
    UDG,
    UDN
} GraphKind;
typedef int VRType;
typedef int VertexType;
typedef struct ArcCell{
    VRType adj;
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct{
    VertexType vexs[MAX_VERTEX_NUM];
    AdjMatrix arcs;
    int vexnum, arcnum;
    GraphKind kind;
} MGraph;




//----------队列---------------------------------
#define MAXQSIZE 100 //队列的最大长度
typedef int Status;
typedef int QElemType;

typedef struct{ //循环队列的C语言描述
    QElemType *base; //初始化动态分配存储空间
    int front;       //头指针，若队列不空，指向队头元素
    int rear;        //尾指针，若队列不空，指向队尾元素的下一个位置
} SqQueue;

//----------------------循环队列的主要操作------------------------
Status InitQueue_Sq(SqQueue &Q){
    if (!(Q.base = (QElemType *)malloc(MAXQSIZE * sizeof(QElemType)))){
        printf("内存分配失败，程序即将退出！\n");
        exit(OVERFLOW);
    }
    Q.front = Q.rear = 0;
    return OK;
}
Status DestoryQueue_Sq(SqQueue &Q){
    if (Q.base){
        free(Q.base);
    }
    Q.base = NULL;
    Q.front = Q.rear = 0;
    return OK;
}
Status QueueEmpty_Sq(SqQueue Q){
    if (Q.rear == Q.front){
        return TRUE;
    }
    else{
        return FALSE;
    }
}
Status EnQueue_Sq(SqQueue &Q, QElemType e){
    if ((Q.rear + 1) % MAXQSIZE == Q.front){ 
        return ERROR;
    } 
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXQSIZE;
    return OK;
} 
Status DeQueue_Sq(SqQueue &Q, QElemType &e){
    if (QueueEmpty_Sq(Q)){
        return ERROR;
    }
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXQSIZE;
    return OK;
}


int LocateVex(MGraph G, VertexType u) {
    int i;
    
    for(i = 0; i < G.vexnum; i++) {
        if(G.vexs[i] == u) {
            return i;
        }
    }
    
    return -1;
}

//算法7.2
Status CreateUDN(MGraph &G){
    VertexType v1, v2;
    int w, i, j;
    printf("请依次输入无向网G的顶点数和弧数\n");
    scanf("%d%d", &G.vexnum, &G.arcnum);
    printf("请依次输入无向网G的顶点名称，用空格隔开\n");
    for (int i = 0; i < G.vexnum; ++i){
        scanf("%d", &G.vexs[i]);
    }
    for (int i = 0; i < G.vexnum; ++i)
        for (int j = 0; j < G.vexnum; ++j)
            G.arcs[i][j].adj = INFINITY;
    printf("请依次输入无向网G每条弧依附的两顶点名称及权值，输完一组按回车\n");
    for (int k = 0; k < G.arcnum; ++k)
    {
        scanf("%d", &v1);
        scanf("%d", &v2);
        scanf("%d", &w);
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        G.arcs[i][j].adj = w;
        G.arcs[j][i] = G.arcs[i][j];
    } 
    return OK;
} // CreateUDN
Status CreateUDG(MGraph &G){
    VertexType v1, v2;
    int i, j;
    printf("请依次输入无向图G的顶点数和弧数\n");
    scanf("%d%d", &G.vexnum, &G.arcnum);
    printf("请依次输入无向图G的顶点名称，用空格隔开\n");
    for (int i = 0; i < G.vexnum; ++i){
        scanf("%d", &G.vexs[i]);
    }
    for (int i = 0; i < G.vexnum; ++i)
        for (int j = 0; j < G.vexnum; ++j)
            G.arcs[i][j].adj = 0;
    printf("请依次输入无向图G每条弧依附的两顶点名称，输完一组按回车\n");
    for (int k = 0; k < G.arcnum; ++k){
        scanf("%d", &v1);
        scanf("%d", &v2);
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        G.arcs[i][j].adj = 1;
        G.arcs[j][i] = G.arcs[i][j];
    }
    return OK;
}

Status CreateDN(MGraph &G)
{
    VertexType v1, v2;
    int w, i, j;
    printf("请依次输入有向网G的顶点数和弧数\n");
    scanf("%d%d", &G.vexnum, &G.arcnum);
    printf("请依次输入有向网G的顶点名称，用空格隔开\n");
    for (int i = 0; i < G.vexnum; ++i){
        scanf("%d", &G.vexs[i]);
    }
    for (int i = 0; i < G.vexnum; ++i)
        for (int j = 0; j < G.vexnum; ++j)
            G.arcs[i][j].adj = INFINITY;
    printf("请依次输入有向网G每条弧依附的两顶点名称及权值，输完一组按回车\n");
    for (int k = 0; k < G.arcnum; ++k){
        scanf("%d", &v1);
        scanf("%d", &v2);
        scanf("%d", &w);
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        G.arcs[i][j].adj = w;
    } 
    return OK;
} // CreateDN

Status CreateDG(MGraph &G){
    VertexType v1, v2;
    int i, j;
    printf("请依次输入有向图G的顶点数和弧数\n");
    scanf("%d%d", &G.vexnum, &G.arcnum);
    printf("请依次输入有向图G的顶点名称，用空格隔开\n");
    for (int i = 0; i < G.vexnum; ++i){
        scanf("%d", &G.vexs[i]);
    }
    for (int i = 0; i < G.vexnum; ++i)
        for (int j = 0; j < G.vexnum; ++j)
            G.arcs[i][j].adj = 0;
    printf("请依次输入有向图G每条弧依附的两顶点名称，输完一组按回车\n");
    for (int k = 0; k < G.arcnum; ++k){
        scanf("%d", &v1);
        scanf("%d", &v2);
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        G.arcs[i][j].adj = 1;
    }
    return OK;
} // CreateDG

//算法7.1
Status CreateGraph(MGraph &G){
    printf("请输入您想构造的图的类型:有向图输入0,有向网输入1,无向图输入2,无向网输入3):");
    scanf("%d", &G.kind);
    switch (G.kind)
    {
    case DG:
        return CreateDG(G); //构造有向图G
    case DN:
        return CreateDN(G); //构造有向网G
    case UDG:
        return CreateUDG(G); //构造无向图G
    case UDN:
        return CreateUDN(G); //构造无向网G
    default:
        return ERROR;
    } 
} //CreateGraph

Status DestroyGraph(MGraph &G){
    if (G.kind % 2){
        for (int i = 0; i < G.vexnum; i++){
            for (int j = 0; j < G.vexnum; j++){
                G.arcs[i][j].adj = INFINITY;
            } 
        }    
    }  
    else{ //若是图
        for (int i = 0; i < G.vexnum; i++){
            for (int j = 0; j < G.vexnum; j++){
                G.arcs[i][j].adj = 0;
            } 
        }     
    }   
    G.vexnum = 0;
    G.arcnum = 0;
} //DestroyGraph
Status PrintAdjMatrix(MGraph G){
    printf("      ");
    for (int i = 0; i < G.vexnum; i++){
        printf(" %3d ", G.vexs[i]);
    }
    printf("\n");
    printf("     +");
    for (int i = 0; i < G.vexnum; i++){
        printf("-----");
    } 
    printf("\n");
    for (int i = 0; i < G.vexnum; i++){
        printf(" %3d |", G.vexs[i]);
        for (int j = 0; j < G.vexnum; j++){
            if (G.arcs[i][j].adj == INFINITY){
                printf("  ∞ ");
            } 
            else{
                printf(" %3d ", G.arcs[i][j].adj);
            }
        }
        printf("\n     |\n");
    }
} //PrintAdjMatrix
VertexType &GetVex(MGraph G, int v){
    if (v >= G.vexnum || v < 0){
        exit(ERROR);
    }
    return G.vexs[v];
} //GetVex
Status PutVex(MGraph &G, VertexType v, VertexType value){
    int k = LocateVex(G, v);
    if (k < 0){
        return ERROR;
    }
    G.vexs[k] = value;
    return OK;
} //PutVex

int FirstAdjVex(MGraph G, VertexType v) {
    int kv,j;
    VRType adj;
    kv = LocateVex(G, v);
    if(kv == -1)
        return -1;  
    if(G.kind == DG || G.kind == UDG) {
        adj = 0;            // 图
    } else if(G.kind == DN || G.kind == UDN) {
        adj = INFINITY;     // 网
    } else {
        return -1;
    }
    for(j = 0; j < G.vexnum; j++) {
        if(G.arcs[kv][j].adj != adj) {
            return j;
        }
    }
    return -1;
}
int NextAdjVex(MGraph G, VertexType v, VertexType w) {
    int kv, kw, j;
    VRType adj;
    kv = LocateVex(G, v);
    if(kv == -1) 
        return -1; 
    kw = LocateVex(G, w);
    if(kw == -1) {
        return -1;  
    }
    if(G.kind == DG || G.kind == UDG) {
        adj = 0;        // 图
    } else if(G.kind == DN || G.kind == UDN) {
        adj = INFINITY; // 网
    } else {
        return -1;
    }
    for(j = kw + 1; j < G.vexnum; j++) {
        if(G.arcs[kv][j].adj != adj) {
            return j;
        }
    }
    return -1;
}
Status InsertVex(MGraph &G, VertexType v){
    int j = 0;
    if (G.kind % 2){
        j = INFINITY;
    }
    G.vexs[G.vexnum] = v;
    for (int i = 0; i <= G.vexnum; i++){
        G.arcs[G.vexnum][i].adj = G.arcs[i][G.vexnum].adj = j;
    }
    G.vexnum++;
    return OK;
} //InsertVex
Status DeleteVex(MGraph &G, VertexType v){
    VRType m = 0;
    if (G.kind % 2){
        m = INFINITY;
    } 
    int k = LocateVex(G, v);
    if (k < 0){ 
        return ERROR;
    } 
    for (int j = 0; j < G.vexnum; j++){
        if (G.arcs[j][k].adj != m){
            G.arcs[j][k].adj = m;
            G.arcnum--;
        }
        if (G.arcs[k][j].adj != m) {
            G.arcs[k][j].adj = m;
            G.arcnum--;
        } 
    }   
    for (int j = k + 1; j < G.vexnum; j++){
        G.vexs[j - 1] = G.vexs[j];
    } 
    for (int i = 0; i < G.vexnum; i++){
        for (int j = k + 1; j < G.vexnum; j++){
            G.arcs[i][j - 1] = G.arcs[i][j];
        } 
    }     
    for (int i = 0; i < G.vexnum; i++){
        for (int j = k + 1; j < G.vexnum; j++){
            G.arcs[j - 1][i] = G.arcs[j][i];
        } 
    }
    G.vexnum--;
    return OK;
} //DeleteVex
Status InsertArc(MGraph &G, VertexType v, VertexType w){
    int v1 = LocateVex(G, v);
    int w1 = LocateVex(G, w);
    if (v1 < 0 || w1 < 0){
        return ERROR;
    }
    G.arcnum++;
    if (G.kind % 2){
        printf("请输入此弧或边的权值: ");
        scanf("%d", &G.arcs[v1][w1].adj);
    }
    else
        G.arcs[v1][w1].adj = 1;
    if (G.kind > 1)
        G.arcs[w1][v1].adj = G.arcs[v1][w1].adj;
    return OK;
} //InsertArc

Status DeleteArc(MGraph &G, VertexType v, VertexType w){
    int j = 0;
    if (G.kind % 2){
        j = INFINITY;
    }
    int v1 = LocateVex(G, v);
    int w1 = LocateVex(G, w);
    if (v1 < 0 || w1 < 0)
        return ERROR;
    G.arcs[v1][w1].adj = j;
    if (G.kind >= 2)
        G.arcs[w1][v1].adj = j;
    G.arcnum--;
    return OK;
} //DeleteArc



//-----------------------深度优先遍历DFS-----------------------------
int visited[MAX_VERTEX_NUM];
Status (*VisitFunc)(int v);
Status Print(int v){
    printf(" %3d ", v);
    return OK;
}
//算法7.5
void DFS(MGraph G, int v){
    visited[v] = TRUE;
    VisitFunc(G.vexs[v]);
    for (int w = FirstAdjVex(G, G.vexs[v]); w >= 0;w = NextAdjVex(G, G.vexs[v], G.vexs[w])){
        if (!visited[w]){
            DFS(G, w);
        } 
    } 
} //DFS
//算法7.4
void DFSTraverse(MGraph G, Status (*Visit)(int v)){
    VisitFunc = Visit;
    for (int v = 0; v < G.vexnum; ++v)
        visited[v] = FALSE;
    for (int v = 0; v < G.vexnum; ++v){
        if (!visited[v])
            DFS(G, v);
    }
} //DFSTraverse



//----------------广度优先遍历 (需要使用队列)BFS------------
//算法7.6
void BFSTraverse(MGraph G, Status (*Visit)(int v)){
    int u;
    SqQueue Q;
    for (int v = 0; v < G.vexnum; ++v){
        visited[v] = FALSE;
    }
    InitQueue_Sq(Q);
    for (int v = 0; v < G.vexnum; ++v){
        if (visited[v])
            continue;
        visited[v] = TRUE;
        Visit(G.vexs[v]);
        EnQueue_Sq(Q, v);
        while (!QueueEmpty_Sq(Q)){
            DeQueue_Sq(Q, u);
            for (int w = FirstAdjVex(G, G.vexs[u]); w >= 0;
                    w = NextAdjVex(G, G.vexs[u], G.vexs[w])){
                if (!visited[w]){
                    visited[w] = TRUE;
                    Visit(G.vexs[w]);
                    EnQueue_Sq(Q, w);
                } 
            }    
        }        
    }
} //BFSTraverse



//----------------------主函数----------------------
int main(){

    printf("\n-------------图的邻接矩阵表示法基本操作测试程序--------------\n\n");
    MGraph G;
    VertexType v1, v2;
    int n;
    printf("->测试图的创建：\n");
    CreateGraph(G);
    // printf("\n->创建成功后图的邻接矩阵:\n\n");
    // PrintAdjMatrix(G);
    //测试图的遍历（深度、广度）
    printf("\n->测试图的遍历:\n");
    printf("->深度优先遍历结果：");
    DFSTraverse(G, Print);

    printf("\n->广度优先遍历结果：");
    BFSTraverse(G, Print);
    printf("\n");
    return 0;
}
