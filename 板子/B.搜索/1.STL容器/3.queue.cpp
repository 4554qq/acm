#include<iostream>
#include<queue>
using namespace std;
const int N =100010;
vector<int> e[N];
int vis[N];
queue<int> q;
void bfs(){
    vis[1] = 1;q.push(1);
    while(q.size()){
        int x = q.front();q.pop();
        cout<<x<<'\n';
        for(auto y : e[x]){
            if(vis[y]) continue;
            vis[y] = 1;
            q.push(y);
        }
    }
}


int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        int a,b;
        cin>>a>>b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    bfs();
    return 0;
}