#include<iostream>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int>> a;
// priority_queue<int> a;

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        int c;
        cin>>c;
        a.push(c);
    }
    while(a.size()){
        int x = a.top();
        cout<<x<<' ';
        a.pop();
    }
    return 0;
}
