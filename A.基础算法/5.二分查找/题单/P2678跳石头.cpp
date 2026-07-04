#include<bits/stdc++.h>
using namespace std;
int L,N,M;
vector<int> arr;
bool check(int x){
    int point = 0,cnt = 0;
    for(int i = 1;i<=N+1;i++){
        if(arr[i]-arr[point]<x) cnt++;
        else point = i;
    }
    return cnt<=M;
}
void solve_find(){
    int l = 0,r = 1e9+1;
    while(l+1<r){
        int mid = (l+r)>>1;
        if(check(mid)){
            l = mid;
        }
        else r = mid;
    }
    cout<<l;
}
int main(){
    cin>>L>>N>>M;
    arr.push_back(0);
    for(int i = 0;i<N;i++){
        int c;cin>>c;
        arr.push_back(c);
    }
    arr.push_back(L);
    solve_find();
    return 0;
}