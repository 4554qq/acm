#include<iostream>
using namespace std;
int n,m,ans;
char g[109][109];
int dx[8] = {0,1,1, 1, 0 ,-1,-1,-1,};
int dy[8] = {1,1,0,-1,-1, -1, 0, 1};
void dfs(int x,int y){
    g[x][y] = '.';
    for(int i = 0;i<8;i++){
        int a = x+dx[i];
        int b = y+dy[i];
        if(a<1||a>n||b<1||b>m) continue;
        if(g[a][b] == '.') continue;
        dfs(a,b);
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j] == 'W'){
                ans++;
                dfs(i,j);
            }
        }
    }
    cout<<ans;
    return 0;
}