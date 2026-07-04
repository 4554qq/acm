#include<iostream>
using namespace std;
using ll = long long;
void solve(){
    ll x,y;
    cin>>x>>y;
    ll c = x>y?x:y;
    ll ans = c*c-c+1;
    if(c&1){
        ans+=(y-x); 
    }
    else{
        ans+=(x-y);
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}