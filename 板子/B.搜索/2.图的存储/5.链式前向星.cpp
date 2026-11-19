#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int N = 10010;
const int M = 1010;
struct edge{
    int v,w,ne;
}e[M];
int n,m,idx,h[N],vis[N];

void add(int a,int b,int c){
    e[idx] = {b,c,h[a]};
    h[a] = idx++;
}

void dfs(int u){
    vis[u] = 1;
    for(int i = h[u]; ~i ;i = e[i].ne){
        int v = e[i].v,w = e[i].w;
        cout<<u<<' '<<v<<' '<<w<<endl;
        if(vis[v])continue;
        dfs(v);
    }
}
int main(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i = 0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        // add(b,a,c);
    }
    dfs(1);
    return 0;
}
/*
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int N = 10010;
const int M = 1010;
int n,m,idx,h[N];
struct edge{ int v,w,ne;}; //存储临边以及编号
edge e[M];

void add(int a,int b,int c){
    e[idx] = {b,c,h[a]};
    h[a] = idx++;
}

void dfs(int u,int fa){
    for(int i = h[u] ; ~i ; i = e[i].ne){
        int v = e[i].v,w = e[i].w;
        if(v == fa) continue;
        cout<<u<<' '<<v<<' '<<w<<endl;
        dfs(v,u); 
    }
}
int main(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i = 0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }
    dfs(1,0);
    return 0;
}
*/