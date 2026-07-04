#include<iostream>
#include<queue>
using namespace std;
const int N = 109;
struct node{
    int x;int y;
};
int n,m;
int g[N][N];
queue<node> q;
node pre[N][N];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
void bfs(int x,int y){
    g[x][y] = 1;
    q.push({x,y});
    while(q.size()){
        node u = q.front();
        q.pop();
        for(int i = 0;i<4;i++){
            int a = u.x+dx[i],b = u.y+dy[i];
            if(a<0||a>=n||b<0||b>=m) continue;
            if(g[a][b]) continue;
            g[a][b] = 1;
            pre[a][b] = u;
            q.push({a,b});
        }   
    }
}
void print(int x,int y){
    if(x == 0&&y == 0){
        puts("(0, 0)");
        return ;
    }
    print(pre[x][y].x,pre[x][y].y);
    //cout<<x<<' '<<y<<'\n';
    cout<<'('<<x<<", "<<y<<')'<<'\n';
}
int main(){
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>g[i][j];
        }
    }
    bfs(0,0); 
    print(n-1,m-1);
    return 0;
}