#include<iostream>
using namespace std;

const int N = 10010;
const int M = 1010;
struct edge{int u,v,w;}e[M];
int n,m;
bool vis[N];

void dfs(int u){
    vis[u] = 1;
    for(int i = 1;i<=m;i++){
        if(u == e[i].u){
            int v = e[i].v;
            int w = e[i].w;
            cout<<u<<' '<<v<<' '<<w<<endl;
            if(vis[v]) continue;
            dfs(v);
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i = 1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        e[i] = {a,b,c};
    }
    dfs(1);
    return 0;
}
