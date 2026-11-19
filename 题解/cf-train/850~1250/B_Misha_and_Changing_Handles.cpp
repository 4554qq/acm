#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int m,n;
queue<string> q[1001];
void ins(string s1,string s2){
    for(int i = 1;i<=m;i++){
        if(q[i].back() == s1){
            q[i].push(s2);
            return ;
        }
    }
    m++;
    q[m].push(s1);
    q[m].push(s2);
    return ;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i = 1;i<=n;i++){
        string s1,s2;
        cin>>s1>>s2;
        ins(s1,s2);
    }
    cout<<m<<endl;
    for(int i = 1;i<=m;i++){
        cout<<q[i].front()<<' '<<q[i].back()<<endl;
    }
    return 0;
}