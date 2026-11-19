#include<iostream>
#include<vector>
using namespace std;
const int N = 10;
int n,m,t,sx,sy,fx,fy,ans;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int g[N][N];
void dfs(int x,int y){
    if(x == fx && y == fy) {ans++;return;}
    for(int i = 0;i<4;i++){
        int a = x+dx[i];
        int b = y+dy[i];
        if(!(a>=1&&a<=n&&b>=1&&b<=m)) continue;
        if(g[a][b]) continue;
        g[a][b]= 1;
        dfs(a,b);
        g[a][b] = 0;
    }
}
int main(){
    cin>>n>>m>>t;
    cin>>sx>>sy>>fx>>fy;
    for(int i = 0;i<t;i++){
        int x,y;
        cin>>x>>y;
        g[x][y] = 1;
    }
    g[sx][sy] = 1;
    dfs(sx,sy);
    cout<<ans;
    return 0;
}