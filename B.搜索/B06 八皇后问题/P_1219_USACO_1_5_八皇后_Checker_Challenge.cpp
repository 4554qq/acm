#include<bits/stdc++.h>
using namespace std;
const int N = 100;
int n,ans;
int pos[N];
int c[N],p[2*N],q[2*N];

void print(){
    if(ans<=3){
        for(int i = 1;i<=n;i++)
            cout<<pos[i]<<' ';
        cout<<'\n';
    }
}
void dfs(int i){
    if(i>n){
        ans++;
        print();
        return ;
    }
    for(int j = 1;j<=n;j++){
        if(c[j]||p[i+j]||q[i-j+n]){
            continue;
        }
        pos[i] = j;
        c[j] = p[i+j] = q[i-j+n] = 1;
        dfs(i+1);
        c[j] = p[i+j] = q[i-j+n] = 0;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    dfs(1);
    cout<<ans;
    return 0;
}