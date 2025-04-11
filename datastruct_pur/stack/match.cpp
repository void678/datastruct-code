#include<bits/stdc++.h>
using namespace std;


stack<int> q;

bool matching(char exp[]);
int main(){

    char s[80];
    cin>>s;

    if(matching(s)) cout<<"matching"<<endl;
    else cout<<"not matching"<<endl;


}

bool matching(char exp[]){

    int state=1;
    char ch=*exp++;

   // cout<<ch<<endl;

    while(ch!='#'&&state){
        switch (ch)
        {
            case '(':
            case '[':
                {
                    q.push(ch);
                    break;
                }
            case ')':
                {
                    if(!q.empty()&&q.top()=='(')
                        q.pop();
                    
                    else state=0;
                    break;
                }
            case ']':
                {
                    if(!q.empty()&&q.top()=='[')
                        q.pop();
                    else state=0;
                    break;
                }
        }
        ch=*exp++;
    }
    if(state&&q.empty()) return 1;
    else return 0;

}