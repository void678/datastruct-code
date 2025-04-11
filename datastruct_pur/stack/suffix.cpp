#include<bits/stdc++.h>
using namespace std;


stack<int> q;

bool op(char ch){
    if(ch=='-'||ch=='+'||ch=='/'||ch=='*')
        return 1;
    else return 0;
}

int cac(char ch,int a,int b){

    if(ch=='+') return (a+b);
    else if(ch=='-') return (b-a);
    else if(ch=='*') return (a*b);
    else return (b/a);

}
int suffix(char s[]){

    int res;
    char ch=*s++;
    while(ch!='#'){
        
        if(!op(ch)) 
            q.push(ch-48);
        
        else{
            int a=q.top(); q.pop();
            int b=q.top(); q.pop();
            q.push(cac(ch,a,b));
        }
        ch=*s++;
    }

    res=q.top();
    return res;

}
int main(){

    char s[80];
    cin>>s;
    cout<<suffix(s)<<endl;

}