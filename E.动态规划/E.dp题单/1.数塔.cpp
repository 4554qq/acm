// #include<iostream>
// using namespace std;
// int r;
// int a[1009][1009];
// int f[1009][1009];
// bool vis[1009][1009];
// int dfs(int x,int y){
//     if(vis[x][y]) return f[x][y];
//     vis[x][y] = true;
//     if(x == r)  f[x][y] = a[x][y];
//     else  f[x][y] = a[x][y]+max(dfs(x+1,y),dfs(x+1,y+1));
//     return f[x][y];
// }
// int main(){
//     cin>>r;
//     for(int i = 1;i<=r;i++){
//         for(int j = 1;j<=i;j++){
//             cin>>a[i][j];
//         }
//     }
//     cout<<dfs(1,1);
//     return 0;
// }
// #include<iostream>
// using namespace std;

// int r;
// int a[1009][1009]; // 既存原始数据，也存计算结果
// bool vis[1009][1009]; // vis 来判断是否计算过

// int dfs(int x, int y){
//     if(vis[x][y]) return a[x][y]; // 如果计算过，返回 a 中存的结果
    
//     vis[x][y] = true;
    
//     // 最后一层，结果就是它自己
//     // a[x][y] 保持不变
//     // if(x == r){
//     // }
//     if(x!=r) {
//         // 关键：直接把结果写回 a[x][y]
//         // 覆盖掉原来的原始值，反正原始值以后也用不到了
//         a[x][y] = a[x][y] + max(dfs(x+1, y), dfs(x+1, y+1));
//     }
//     return a[x][y];
// }
// int main(){
//     cin >> r;
//     for(int i = 1; i <= r; i++){
//         for(int j = 1; j <= i; j++){
//             cin >> a[i][j];
//         }
//     }
//     cout << dfs(1, 1);
//     return 0;
// }
/*
#include<iostream>
using namespace std;

int r;
int a[1009][1009]; // 既存原始数据，也存计算结果
bool vis[1009][1009]; // 依然需要 vis 来判断是否计算过

int dfs(int x, int y){
    if(vis[x][y]) return a[x][y]; // 如果计算过，返回 a 中存的结果
    
    vis[x][y] = true;
    
    if(x == r){
        // 最后一层，结果就是它自己
        // a[x][y] 保持不变
    } else {
        // 关键：直接把结果写回 a[x][y]
        // 覆盖掉原来的原始值，反正原始值以后也用不到了
        a[x][y] = a[x][y] + max(dfs(x+1, y), dfs(x+1, y+1));
    }
    
    return a[x][y];
}

int main(){
    cin >> r;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= i; j++){
            cin >> a[i][j];
        }
    }
    cout << dfs(1, 1);
    return 0;
}
*/
#include<iostream>
using namespace std;
int r;
int a[1009][1009];
int main(){
    cin>>r;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= i; j++){
            cin >> a[i][j];
        }
    }
    for(int i = r-1;i>=1;i--){
        for(int j = 1;j<=i;j++)
            a[i][j]+=max(a[i+1][j],a[i+1][j+1]);
        }
    cout<<a[1][1];
    return 0;
}