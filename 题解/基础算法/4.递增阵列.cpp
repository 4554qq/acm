#include<iostream>
using namespace std;
long long num[200009];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>num[i];
    }
    long long ans = 0;
    for(int i = 1;i<n;i++){
        if(num[i+1]<num[i]){
            ans+=(num[i]-num[i+1]);
            num[i+1] = num[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}