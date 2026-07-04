#include<iostream>
#include<cstring>
#include<vector>

using namespace std;
int main(){
    string a,b;
    cin>>a>>b;
    int n = a.size();
    int m = b.size();
    vector<int> f(m+1);
    for(int j = 1;j<=m;j++) f[j] = j;

    for(int i = 1;i<=n;i++){
        int t1 = f[0]++;
        for(int j = 1;j<=m;j++){
            int t2 = f[j];
            if(a[i-1] == b[j-1]){
                f[j] = t1;
            }
            else{
                f[j] = min(t1,min(f[j],f[j-1]))+1;
            }
            t1 = t2;
        }
    }
    cout<<f[m];
    return 0;
}
// #include<iostream>
// #include<cstring>
// #include<vector>

// using namespace std;
// int main(){
//     string a,b;
//     cin>>a>>b;
//     int n = a.size();
//     int m = b.size();
//     vector<vector<int>> f(n+1,vector<int>(m+1,0));
//     for(int i = 1;i<=n;i++) f[i][0] = i;
//     for(int j = 1;j<=m;j++) f[0][j] = j;
//     for(int i = 1;i<=n;i++){
//         for(int j = 1;j<=m;j++){
//             if(a[i-1] == b[j-1]){
//                 f[i][j] = f[i-1][j-1];
//             }
//             else{
//                 f[i][j] = min(f[i-1][j-1],min(f[i][j-1],f[i-1][j]))+1;
//             }
//         }
//     }
//     // for(int i = 1;i<=n;i++){
//     //     for(int j = 1;j<=m;j++){
//     //         cout<<f[i][j]<<' ';
//     //     }
//     //     cout<<'\n';
//     // }
//     cout<<f[n][m];
//     return 0;
// }  