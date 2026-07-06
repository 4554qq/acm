#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<char>> s (n+1,vector<char>(m+1));
    vector<vector<int>> num (n+1,vector<int>(m+1));
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin>>s[i][j];
            if(s[i][j] == '*'){
                for(int k = 0;k<8;k++){
                    int ni = i+dx[k];
                    int nj = j+dy[k];
                    if(ni >= 1 && ni <=n && nj >= 1 && nj <=m){
                        num[ni][nj]++;
                    }
                }
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(s[i][j] == '*'){
                cout<<'*';
            }
            else{
                cout<<num[i][j];
            }
        }
        cout<<'\n';
    }
    return 0;
}