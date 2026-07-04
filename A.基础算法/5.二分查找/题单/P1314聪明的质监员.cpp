#include<bits/stdc++.h>
using namespace std;
int n,m;//矿石个数和区间个数
long long S,ans = 1e18;//标准值
int W;//重量参数
vector<int> w;//重量
vector<int> v;//价值
vector<long long> sw(1,0);
vector<long long> sv(1,0);
vector<int> l;//区间左边界
vector<int> r;//右边界
bool fun(int W){
    sw.assign(1,0);
    sv.assign(1,0);
    long long y = 0;
    for(int i = 1;i<=n;i++){
        if(w[i]>=W){
            sw.push_back(sw[i-1]+1);
            sv.push_back(sv[i-1]+v[i]);
        }
        else{
            sw.push_back(sw[i-1]);
            sv.push_back(sv[i-1]);
        }
    }
    for(int i = 1;i<=m;i++){
        y+=(sw[r[i]]-sw[l[i]-1])*(sv[r[i]]-sv[l[i]-1]);
    }
    ans = min(ans,llabs(y-S));
    return y<=S;//检验结果
}
void solve_find(){
    int l = 0,r = 1e6+1;//二分W重量参数
    while(l+1<r){
        int mid = l+r>>1;
        if(fun(mid))    r = mid;
        else l = mid;
    }
    cout<<ans;
}
int main()
{
    cin>>n>>m>>S;
    w.push_back(0);
    v.push_back(0);
    for(int i=1;i<=n;i++){
        int c,d;
        cin>>c>>d;
        w.push_back(c);
        v.push_back(d);
    }
    l.push_back(0);
    r.push_back(0);
    for(int i = 1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        l.push_back(a); 
        r.push_back(b);
    }
    solve_find();
    return 0;
}