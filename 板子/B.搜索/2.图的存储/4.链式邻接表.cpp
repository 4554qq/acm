#include<iostream>
#include<vector>
using namespace std;
const int N = 10010;
struct edge{
    int u,v,w;
};
vector<edge> e;
vector<int> h[N];
int n,m,vis[N];

void add(int a,int b,int c){
    e.push_back({a,b,c});
    h[a].push_back(e.size()-1);
}

void dfs(int u){
    vis[u] = 1;
    for(int i = 0;i<h[u].size();i++){
        int j = h[u][i];
        int v = e[j].v,w = e[j].w;
        cout<<u<<' '<<v<<' '<<w<<endl;
        if(vis[v]) continue;
        dfs(v);
    }
}
int main(){
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        // add(b,a,c);
    }
    dfs(1);
    return 0;
}