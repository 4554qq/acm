#include<iostream>
#include<vector>
using namespace std;
const int N = 20;
int n,m,ans;
int dx[] = {2,1,-1,-2};
int dy[] = {1,2,2,1};
//int g[N][N];
void dfs(int x,int y){
    if(x == n && y == m) {ans++;return;}
    for(int i = 0;i<4;i++){
        int a = x+dx[i];
        int b = y+dy[i];
        if(a<0||a>n||b<0||b>m) continue;
        //if(g[a][b]) continue;
        //g[a][b] = 1;
        dfs(a,b);
        //g[a][b] = 0;
    }
}
int main(){
    cin>>n>>m;
    dfs(0,0);
    cout<<ans;
    return 0;
}