#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 109;
const int M = 109;
int n,m,ans;
char g[N][M];
int dx[8] = {-1,-1,-1,0,1,1,1,0};
int dy[8] = {-1,0,1,1,1,0,-1,-1};

void dfs(int x,int y){
    g[x][y] = '.';
    for(int i = 0;i<8;i++){
        int a = x+dx[i];
        int b = y+dy[i];
        if(a<=0||a>n||b<=0||b>m) continue;
        if(g[a][b] == '.') continue;
        dfs(a,b);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=m;j++)
            cin>>g[i][j];
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(g[i][j] =='W'){
                ans++;
                dfs(i,j);
            }
        }
    }
    cout<<ans;
    return 0;
}