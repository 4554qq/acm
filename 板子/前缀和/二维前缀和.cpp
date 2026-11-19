#include<iostream>
using namespace std;
int s[5020][5020];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        int x,y,v;
        cin>>x>>y>>v;
        s[x+1][y+1] += v;
    }
    for(int i = 1;i<=5001;i++){
        for(int j = 1;j<=5001;j++){
            s[i][j] += s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        }
    }
    int res = 0;
    for(int i = m;i<=5001;i++){
        for(int j = m;j<=5001;j++){
            res = max(res,s[i][j] - s[i-m][j]-s[i][j-m]+s[i-m][j-m]);
        }
    }
    cout<<res;
    return 0;
}