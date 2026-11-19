#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n,mx = 1,dep[2001],f[2001];
vector<int> g[2001];
void solve_x();

void dfs(int u){
    for(int i = 0;i<g[u].size();i++){
        int v = g[u][i];
        dep[v] = dep[u]+1;
        mx = max(dep[v],mx);
        dfs(v);
    }
}
void solve(){
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>f[i];
        if(f[i] == -1)continue;
        g[f[i]].push_back(i);//存边
    }
    for(int i = 0;i<=n;i++){
        if(f[i] == -1){
            dep[i]=1;
            dfs(i);
        }
    }
    cout<<mx<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--) solve_x();
    return 0;
}
int lingdao[2001]; //该员工的上司
int find(int x){
    int cnt = 0;
    while(x !=-1){
        x = lingdao[x];
        cnt++;
    }
    return cnt;
}
void solve_x(){ // 暴力用一个数组从结点找到根
    int n,ans = 0;
    cin>>n;
    for(int i = 1;i<=n;i++) cin>>lingdao[i];

    for(int i = 1;i<=n;i++){
        ans = max(ans,find(i));
    }
    cout<<ans;
}