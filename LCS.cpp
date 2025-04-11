#include<iostream>
#include<string.h>
using namespace std;

void substring(char s[],char t[]){

    int i=0,j=0;
    int sl=strlen(s),tl=strlen(t);
    int dp[sl+1][tl+1];
    memset(dp,0,sizeof(dp));

    int ml=0,nl=0;
    for(int i=1;i<=sl;i++){
        for(int j=1;j<=tl;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                if(dp[i][j]>ml){
                    ml=dp[i][j];
                    nl=i;
                }
            }
            else dp[i][j]=0;
        }
    }
    cout<<"最长公共子串长度=";
    cout<<ml<<endl;

    if(ml>0){
        for(int k=nl-ml;k<nl;k++){
            cout<<s[k];
        }
    }else cout<<"无公共子串"<<endl;

}

int main(){
    char s1[100],s2[100];

    cout<<"请输入第一个字符串:";
    scanf("%s",s1);
    cout<<"请输入第二个字符串";
    scanf("%s",s2);

    substring(s1,s2);
    return 0;
}