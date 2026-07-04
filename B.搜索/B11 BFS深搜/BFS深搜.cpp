#include<iostream>
#include<queue>
using namespace std;
const int N = 109;
vector<int> e[N];
queue<int> q;
int vis[109];
void bfs(){
    vis[1] = 1;
    q.push(1);
    while(q.size()){
        int x = q.front();
        q.pop();
        cout<<x<<' ';
        for(int y:e[x]){
            if(vis[y]) continue;
            q.push(y);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    int a ,b;
    for(int i = 0;i<m;i++){
        cin>>a>>b;
        e[a].push_back(b);
    }
    bfs();
    return 0;
}