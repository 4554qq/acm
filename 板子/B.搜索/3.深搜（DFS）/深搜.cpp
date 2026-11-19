#include<iostream>
#include<vector>
using namespace std;

const int N = 10010;
int n,m,a,b,vis[N];
vector<int> e[N];

void dfs(int u){
    vis[u] = true;
    for(auto v : e[u]){
        if(vis[v]) continue;
        cout<<u<<"->"<<v<<endl;
        dfs(v);
    }
}
int main(){
    cin>>n>>m;
    for(int i = 1 ; i<=m ; i++){
        cin>>a>>b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(1);
    return 0;
}