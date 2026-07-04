#include<bits/stdc++.h>
using namespace std;

int n,m,ans;
int g[19][19];
int dx[4] = {2,1,-1,-2};
int dy[4] = {1,2,2,1};
void dfs(int x,int y){
    if(x == n && y == m) {ans++;return ;}
    for(int i = 0;i<4;i++){
        int a = x+dx[i],b =y+dy[i];
        if(a<0||a>n||b<0||b>m) continue;
        if(g[a][b]) continue;
        g[a][b] = 1;
        dfs(a,b);
        g[a][b] = 0;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    g[0][0] = 1;
    dfs(0,0);
    cout<<ans<<endl;
    return 0;
}