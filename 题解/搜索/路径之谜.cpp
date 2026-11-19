#include <iostream>
#include <vector>
using namespace std;
int n;
int row[21],col[21],vis[21][21];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
vector<int> path;
void dfs(int x,int y){
  if(row[x]<0||col[y]<0) return;
  if(x == n-1 && y == n-1){
    bool ok = true;
    for(int i = 0;i<n;i++) if(row[i]||col[i]) ok = false;
    if(ok){
      for(int v : path) cout<<v<<' ';
    }
    return ;
  }

  for(int k=0;k<4;k++){
    int a = x+dx[k],b = y+dy[k];
    if(a<0||a>=n||b<0||b>=n||vis[a][b]) continue;
    vis[a][b] = 1;
    row[a]--;
    col[b]--;
    path.push_back(a*n+b);
    dfs(a,b);
    path.pop_back();
    col[b]++;
    row[a]++;
    vis[a][b] = 0;
  }
}
int main(){
  cin>>n;
  for(int i = 0;i<n;i++){
    cin>>col[i];
  }
  for(int i = 0;i<n;i++){
    cin>>row[i];
  }
  col[0]--;
  row[0]--;
  vis[0][0] = 1;
  path.push_back(0);
  dfs(0,0);
  return 0;
}