#include<bits/stdc++.h>
#define db double
using namespace std;
db a,b,c,d;
db fun(db x){
    return a*x*x*x+b*x*x+c*x+d;
}
db find(db l,db r){
    while(r-l>0.0001){
        db mid = (l+r)/2;
        if(fun(mid)*fun(r)<0)   l = mid;
        else    r = mid;
    }
    return l;
}
int main()
{
    cin>>a>>b>>c>>d;
    for(int i = -100;i<100;i++){
        double y1 = fun(i),y2 = fun(i+1);
        if(!y1){
            printf("%.2lf ",1.0*i);
        }
        if(y1*y2<0){
            printf("%.2lf ",find(i,i+1));
        }
    }
    return 0;
}