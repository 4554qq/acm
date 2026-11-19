#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n;
    cin>>n;
    int d[2][26] = {0};
    for(int i = 0;i<n;i++){
        string s;
        cin>>s;
        d[0][s[0]-'a']<=d[1][s[0]-'a']?d[0][s[0]-'a']++:d[1][s[0]-'a']++;
    }
    int ans = 0;
    for(int i = 0;i<2;i++){
        for(int j = 0;j<26;j++){
            // cout<<d[i][j]<<' ';
            for(int k = 1;k<=d[i][j];k++){
                ans+=(k-1);
            }
        }
        // cout<<'\n';
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--) solve();
    return 0;
}