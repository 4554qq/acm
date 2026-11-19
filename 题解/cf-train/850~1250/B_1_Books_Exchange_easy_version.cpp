#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n;
    cin>>n;
    int num[201] = {0};
    for(int i = 1;i<=n;i++) cin>> num[i];
    for(int i = 1;i<=n;i++){
        int day = 1;
        int c = num[i];
        while(i != c){
            day++;
            c = num[c];
        }
        cout<<day<<' ';
    }
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin>>t;
    while(t--) solve();
    return 0;
}