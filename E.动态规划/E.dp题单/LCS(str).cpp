#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

using ll = long long;

string a,b;
int n,m;
int maxlen,End;
void LCS(){
    cin>>a>>b;
    int n = a.size();
    int m = b.size();
    vector<vector<int>> f (n+1,vector<int>(m+1,0));
    int i,j;
    for(i = 1;i<=n;i++){
        for(j = 1;j<=m;j++){
            if(a[i-1] == b[j-1]){
                f[i][j] = f[i-1][j-1]+1;
                if(f[i][j]>maxlen){    
                    maxlen = f[i][j];
                    End = i-1;
                }
            }
            else{
                f[i][j] = 0;
            }
            
        }
    }
    cout<<maxlen<<endl;
}
void getLCS(){
    for(int i = End-maxlen+1;i<=End;i++)
        cout<<a[i];
}
int main(){
    int t = 1;
    //cin>>t;
    while(t--){
        LCS();
        getLCS();
    }
    return 0;
}