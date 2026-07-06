#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> dir(n);
    vector<string> name(n);
    for(int i = 0; i < n; i++){
        cin >> dir[i] >> name[i];
    }

    int cur = 0;
    int a, s;
    while(m--){
        cin >> a >> s;
        if(dir[cur] == a){
            // move counterclockwise
            cur = (cur - s % n + n) % n;
        } else {
            // move clockwise
            cur = (cur + s) % n;
        }
    }
    cout << name[cur] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin>>t;
    while(t--) solve();
    return 0;
}
