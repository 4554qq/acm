#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int n,m;
string a,b;
int f[1009][1009];
int p[1009][1009];
void LCS(){
    cin>>a>>b;
    n = a.size();
    m = b.size();
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if (a[i-1] == b[j-1]){
                f[i][j] = f[i-1][j-1]+1;
                p[i][j] = 1;
            }
            else if(f[i][j-1]>f[i-1][j]){
                f[i][j] = f[i][j-1];
                p[i][j] = 2;
            }
            else{
                f[i][j] = f[i-1][j];
                p[i][j] = 3;
            }
        }
    }
    cout<<f[n][m]<<endl;
}
void getLCS(){
    int i=n,j=m,k=f[n][m];
    char s[200];
    while(i>0&&j>0){
         if(p[i][j] == 1){
        //if(a[i-1] == b[j-1]){
            s[k--] = a[i-1];
            i--;
            j--;
        }
        else if(p[i][j] == 2){
        //else if(f[i][j-1]>f[i-1][j]){
            j--;
        }
        else if(p[i][j] == 3){
        //else{
            i--;
        }
    }
    for(i = 1;i<=f[n][m];i++){
        printf("%c",s[i]);
    }
}
int main(){
    LCS();
    getLCS();    
    return 0;
}