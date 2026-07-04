#include<bits/stdc++.h>
using namespace std;

int g[6][6];
int dx[5] = {-1,0,1,0};
int dy[5] = {0,1,0,-1};
int n,m,t,sx,sy,fx,fy,a,b,ans;
void dfs(int x,int y){
    if(x == fx&& y == fy){ans++;return ;}
    for(int i = 0;i<4;i++){
        int a = x+dx[i],b = y+dy[i];
        if(a < 1||a>n||b<1||b>m) continue;
        if(g[a][b]) continue;
        g[a][b] = 1;
        dfs(a,b);
        g[a][b] = 0;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>t;
    cin>>sx>>sy>>fx>>fy;
    for(int i = 0;i<t;i++){
        cin>>a>>b;
        g[a][b] = 1;
    }
    g[sx][sy] = 1;
    dfs(sx,sy);
    cout<<ans;
    return 0;
}