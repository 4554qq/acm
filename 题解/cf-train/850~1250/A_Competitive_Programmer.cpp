#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        string c;
        int flag = 0;
        int cnt = 0;
        int sum = 0;
        cin>>c;
        for(int j = 0;j<c.size();j++){
            if(c[j] == '0'){
                flag = 1;
            }
            sum+=int(c[j]-'0');
            if(int(c[j]-'0')%2 == 0){
                cnt++;
            }
        }
        cnt--;
        if(flag&&sum%3 == 0&&cnt>0)
            cout<<"red"<<endl;
        else
            cout<<"cyan"<<endl;
    }
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