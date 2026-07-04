#include<bits/stdc++.h>
using namespace std;

vector<int> A;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        int c;
        cin>>c;
        A.push_back(c);
    }
    for(int i = 0;i<m;i++){
        int c;
        int ans = 0;
        cin>>c;
        int l = 0,r = n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(A[mid]>=c){
                r = mid-1;ans = mid;
            }
            else l= mid+1;
        }
        if(A[ans] == c) cout<<ans+1<<' ';
        else cout<<-1<<' ';
    }
    return 0;
}