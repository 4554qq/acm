#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
const int INF = 1e9+9;
int n,m,s;
struct edge{int v,w;};
vector<edge> e[N];
int d[N],vis[N];
void dijkstra(int s){
    for(int i = 0;i<=n;i++) d[i] = INF;
    d[s] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,s});
    while(q.size()){
        auto cur = q.top();
        q.pop();
        int u = cur.second;
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto ed : e[u]){
            int v = ed.v;
            int w = ed.w;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                q.push({d[v],v});
            }
        }
    }
}
int main(){
    cin>>n>>m>>s;
    for(int i = 0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        e[a].push_back({b,c});
    }
    dijkstra(s);
    for(int i = 1;i<=n;i++){
        if(d[i] == INF) cout<<-1;
        else cout<<d[i];

        cout<< (i == n?'\n':' ');
    }
    return 0;
}
