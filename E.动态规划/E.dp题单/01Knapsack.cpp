#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    cin>>m>>n;
    vector<int> w(n+1,0);
    vector<int> v(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>w[i]>>v[i];
    }
    vector<vector<int>> f(n+1,vector<int>(m+1,0));
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(j<w[i])
                f[i][j] = f[i-1][j];
            else
                f[i][j] = max(f[i-1][j],f[i-1][j-w[i]]+v[i]);
        }
    }
    cout<<f[n][m];
    return 0;
}