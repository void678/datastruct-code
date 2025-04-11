#include<bits/stdc++.h>
using namespace std;

#define Max_Size 20
typedef struct{
    int x,y;
}node;
node pre[Max_Size][Max_Size];

int mp[Max_Size][Max_Size],vis[Max_Size][Max_Size],f[Max_Size][Max_Size];
int n,m;
int dir[8][2]={{-1,1},{-1,0},{-1,-1},{0,1},{0,-1},{1,-1},{1,0},{1,1}};
queue<pair<int,int> >q;


void print(int x, int y) {
    if (x == 0 && y == 0) { 
        printf("<%d,%d> -> ", x, y);
        return;
    }
    print(pre[x][y].x, pre[x][y].y); 
    printf("<%d,%d> -> ", x, y); 
    
}

void bfs(int u,int v){
    f[u][v]=0,vis[u][v]=1;
    q.push(make_pair(u,v));


    while(!q.empty()){
        int x=q.front().first,y=q.front().second;
        
        for(int i=0;i<8;i++){
            int xx=x+dir[i][0],yy=y+dir[i][1];
            if(xx<0||xx>=m||yy<0||yy>=n||vis[xx][yy]||mp[xx][yy]) continue;
        
            vis[xx][yy]=1;
            q.push(make_pair(xx,yy));
            f[xx][yy]=f[x][y]+1;

            pre[xx][yy].x=x,pre[xx][yy].y=y;
        }
        q.pop();
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%4d",f[i][j]);
        }
        cout<<endl;
    }

    if(f[m-1][n-1]!=-1){
        print(m-1,n-1);
        cout<<"success"<<endl;
    }
    
}


//0能走 1不能走
int main(){

    memset(mp,1,sizeof(mp));
    memset(f,-1,sizeof(f));
    memset(vis,0,sizeof(vis));
   
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>mp[i][j];
        }
    }

    bfs(0,0);
    return 0;
}