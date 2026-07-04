#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int k = 1;k<=n;k++)
        cout<<(long long)(k*k)*(k*k-1)/2-4*(  k-1)*(k-2)<<endl;
    return 0;
}