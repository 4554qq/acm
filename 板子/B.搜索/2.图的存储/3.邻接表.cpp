#include<iostream>
#include<vector>
using namespace std;
const int N = 10010;
int n,m,vis[N];
struct edge{
    int v,w;
};
vector<edge> e[N];

void dfs(int u){
    vis[u] = 1;
    for(auto ed : e[u]){
        int v = ed.v,w = ed.w;
        cout<<u<<' '<<v<<' '<<w<<' '<<endl;
        if(vis[v])continue;
        dfs(v);
    }
}
int main(){
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        e[a].push_back({b,c});
        // e[b].push_back({a,c});
    }
    dfs(1);
    return 0;
}
/*
#include<iostream>
#include<vector>
using namespace std;
const int N = 10010;
int n,m;
struct edge{
    int v,w;
};
vector<edge> e[N];
void dfs(int u,int fa){
    for(auto ed : e[u]){
        int v = ed.v , w = ed.w;
        cout<<u<<' '<<v<<' '<<w<<endl;
        if(v == fa) continue;
        dfs(v,u);
    }
}
int main(){
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        e[a].push_back({b,c});
        // e[b].push_back({a,c});
    }
    dfs(1,0);
    return 0;
}
*/