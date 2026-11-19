#include<iostream>

using namespace std;
const int N = 110;
int n,ans;
int pos[N],c[N],p[N],q[N];
void print(){
    if(ans<=3){
        for(int i = 1;i<=n;i++){
            cout<<pos[i]<<' ';
        }
        cout<<'\n';
    }
}

void dfs(int i){
    if(i>n){ans++;print();return;}
    for(int j = 1;j<=n;j++){
        if(c[j]||p[i+j]||q[i-j+n])continue;
        pos[i] = j;
        c[j] = p[i+j] = q[i-j+n] = 1;
        dfs(i+1);
        c[j] = p[i+j] = q[i-j+n] = 0;
    }
}
int main(){
    cin>>n;
    dfs(1);
    cout<<ans;
    return 0;
}