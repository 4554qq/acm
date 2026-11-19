#include<iostream>
#include<queue>

using namespace std;
priority_queue<int,vector<int>,greater<int>> a;
int main(){
    int n;
    long long ans = 0;
    cin>>n;
    for(int i = 0;i<n;i++){
        int c;cin>>c;
        a.push(c);
    }
    while(a.size()>1){
        long long sum = 0;
        sum = a.top();
        a.pop();
        sum += a.top();
        ans += sum;
        a.pop();
        a.push(sum);
        }
    cout<<ans<<endl;
    return 0;
}