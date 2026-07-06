#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> w(n+1,0);
    vector<int> v(n+1,0);
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i = 1;i<=n;i++){
        cin>>w[i]>>v[i];
    }
    for(int i = 1;i<=m;i++){
        for(int j = 1;j<=n;j++){
            if(j>=w[i]){
                dp[i][j] = max(dp[i-1][j-w[i]]+v[i],dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[m][n];
    return 0;
}

#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> w(n+1,0);
    vector<int> v(n+1,0);
    vector<int> dp(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>w[i]>>v[i];
    }
    for(int i = 1;i<=m;i++){
        for(int j = 1;j<=n;j++){
            if(j>=w[i]){
                dp[i][j] = max(dp[i-1][j-w[i]]+v[i],dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[m][n];
    return 0;
}