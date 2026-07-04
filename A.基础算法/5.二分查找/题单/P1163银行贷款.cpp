#include<bits/stdc++.h>
using namespace std;
int a ,b, c;
bool check(double x){
    double s = a;
    for(int i = 1;i<=c;i++){
        s = s*(1+x)-b;
    }
    return s>=0;
}
double find(){
    double l = 0,r = 10;
    while(r-l>1e-5){
        double mid = (l+r)/2;
        if(check(mid))r = mid;
        else l = mid;
    }
    return r;
}
int main(){
    cin>>a>>b>>c;
    cout<<fixed<<setprecision(1)<<find()*100;
    return 0;
}