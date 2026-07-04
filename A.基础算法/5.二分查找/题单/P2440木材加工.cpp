#include<bits/stdc++.h>
using namespace std;
int n,k,len;
vector<int> arr;
int fun(int x){
    int y = 0;
    for(int i = 0;i<n;i++){
        y += arr[i]/x;
    }
    return y;
}
void solve()
{
    int l = 0,r = 1e8+1;
    while(l+1<r){
        int mid = (l+r)/2;
        if(fun(mid)>=k) l = mid;
        else r = mid;
    }
    cout<<l;
}

int main()
{
    cin>>n>>k;
    for(int i = 0;i<n;i++){
        int c = 0;cin>>c;
        arr.push_back(c);
    }
    solve();
    return 0;
}