#include<iostream>
#include<queue>
using namespace std;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int n;
int map[100][100];
queue<pair<int,int>> q;
pair<int,int> pre[100][100];
void bfs(){
    map[0][0]=1;
    q.push({0,0});
    while(q.size()){
        auto u=q.front();q.pop();
        for(int i = 0;i<4;i++){
            int a = u.first+dx[i],b = u.second+dy[i];
            if(a<0||a>=n||b<0||b>=n) continue;
            if(map[a][b]) continue;
            map[a][b] = 1;
            pre[a][b]=u;
            q.push({a,b});
        }
    }
}
int main(){
    cin>>n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>map[i][j];
        }
    }
    bfs();
    return 0;
}