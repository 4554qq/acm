#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> w(n+1,0);
    vector<int> v(n+1,0);
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i = 1;i<=n;i++){
        cin>>w[i]>>v[i];
    }
    for(int i = 1;i<=n ;i++){
        for(int j = 1;j<=m;j++){
            if(j>=w[i]){
                dp[i][j] = max(dp[i-1][j],dp[i][j-w[i]]+v[i]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[n][m];
    return 0;
}