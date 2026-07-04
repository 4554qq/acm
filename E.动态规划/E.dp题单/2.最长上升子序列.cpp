/*
#include<iostream>
using namespace std;
int a[5009],f[5009];

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>a[i];
        f[i] = 1;
    }
    int ans = 1;
    int j = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<i;j++){
            if(a[i]>a[j]&&f[j]+1>f[i]){
                f[i] = f[j]+1;
            }
        }
        ans = max(ans,f[i]);
    }
    cout<<ans;
    return 0;
}
*/
#include<iostream>
using namespace std;
int b[5009] = {0};
int len;
int find(int k){
    int l = 0,r = len+1;
    while(l+1<r){
        int mid = l+r>>1;
        if(k<=b[mid]) r = mid;
        else    l = mid;//k>=b[mid]
    }
    return r;
}
int main(){
    int n= 0;
    cin>>n;
    int c;
    for(int i = 1;i<=n;i++){
        cin>>c;
        if(c>b[len]){
            b[++len] = c;
        }  
        else{
            int j = find(c);
            b[j] = c;
        }
    }
    cout<<len<<endl;
    return 0;
}