#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
double a[N],b[N],c[N];
int n,k;
bool check(double x){
    double s = 0;
    for(int i = 1;i<=n;++i) c[i] = a[i] - x*b[i];
    sort(c+1,c+n+1);
    for(int i = k+1;i<=n;i++)   s+=c[i];
    return s>=0;
}
double find(){
    double l = 0,r = 1;
    while(r-l>1e-4){
        double mid = (l+r)/2;
        if(check(mid))  l = mid;
        else r = mid;
    }
    return l;
}
int main(){
    while(cin>>n>>k,n){
        for(int i = 1;i<=n;i++) cin>>a[i];
        for(int i = 1;i<=n;i++) cin>>b[i];
        cout<<fixed<<setprecision(0)<<(find()*100)<<'\n';
    }
    return 0;
}