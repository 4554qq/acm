#include<iostream>
#include<queue>
using namespace std;
const int N = 1010;
int n,m,ans;
vector<int> e[N];
int vis[N];
queue<int> q;
void bfs(){
    vis[1] = 1;q.push(1);
    cout<<1<<' ';
    while(q.size()){
        int u = q.front();
        q.pop();
        for(auto v : e[u]){
            if(vis[v])continue;
            cout<<v<<' ';
            vis[v] = 1;
            q.push(v);
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        e[a].push_back(b);
        // e[b].push_back(a);
    }
    bfs();
    return 0;
}