#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 29;
const int T = 100009;
int machine[N][N];
int cost[N][N];
int order[N*N];
int finish[N];
int step[N];
bool busy[N][T];
int n,m,ans;
void solve(){
    cin>>m>>n; // m 工序 n 工件
    for(int i = 0;i<n*m;++i){
        cin>>order[i];
    }
    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j){
            cin>>machine[i][j];
        }
    }
    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j){
            cin>>cost[i][j];
        }
    }
    for(int i = 0;i<n*m;++i){
        int now = order[i]-1;
        int cur_step = step[now];
        int mac = machine[now][cur_step];
        int t = cost[now][cur_step];
        int cnt = 0;
        for(int j = finish[now]+1;;j++){
            if(!busy[mac][j]){
                cnt++;
            }
            else{
                cnt = 0;
            }
            if(cnt == t){
                for(int k =j-t+1;k<=j;k++){
                    busy[mac][k] = true;
                }
                finish[now] = j;
                ans = max(ans,j);
                break;
            }
        }
        step[now]++;
    }
    cout<<ans;
}
int main(){
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}