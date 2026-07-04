#include<bits/stdc++.h>
#define MAX 1000009
using namespace std;
int n,m;
int an[MAX],d[MAX],s[MAX],j[MAX];
long long sn[MAX];
bool check(int x){
    memset(sn,0,sizeof(sn));
    for(int i = 1;i<=x;i++){
        sn[s[i]]+=d[i];
        sn[j[i]+1]-=d[i];
    }
    for(int i = 1;i<=n;i++){
        sn[i] = sn[i-1]+sn[i];
        if(sn[i]>an[i])
        return false;
    }
    return true;
}
void solve_find(){
    int l = 0,r = m+1;
    while(l+1<r){
        int mid = l+r>>1;
        if(check(mid))  l = mid;
        else r = mid;
    }
    if(r == m+1)    cout<<0;
    else cout<<-1<<endl<<r;
}
int main()
{
    cin>>n>>m;
    for(int i = 1;i<=n;i++) cin>>an[i];
    for(int i = 1;i<=m;i++) cin>>d[i]>>s[i]>>j[i];
    solve_find();
    return 0;
}