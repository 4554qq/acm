#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n;
    cin>>n;
    int t1,t2,ans1 = 0,ans2 = 0;
    cin>>t1>>t2;

    int com[5][5] = {{0,2,1,1,2},{1,0,2,1,2},{2,1,0,2,1},{2,2,1,0,1},{1,1,2,2,0}};
    
    vector<int> T1(t1);
    vector<int> T2(t2);
    
    for(int i = 0;i<t1;i++) cin>>T1[i];
    for(int i = 0;i<t2;i++) cin>>T2[i];

    for(int i = 0;i<n;i++){
        if(com[T1[i%t1]][T2[i%t2]] == 1) ans1++;
        else if(com[T1[i%t1]][T2[i%t2]] == 2) ans2++;
    }
    cout<<ans1<<' '<<ans2<<endl;
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