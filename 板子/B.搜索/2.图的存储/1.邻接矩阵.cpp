#include<iostream>
using namespace std;
const int N = 10010;
int n,m;
int w[N][N];bool vis[N];

void dfs(int u){
    vis[u] = true;
    for(int v = 1;v<=n;v++){
        if(w[u][v])
        cout<<u<<' '<<v<<' '<<w[u][v]<<endl; 
        if(vis[v]) continue;
        dfs(v);
    }
}
int main(){
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        w[a][b] = c;
        //e[b][a] = c;   
    }
    dfs(1);
    return 0;
}