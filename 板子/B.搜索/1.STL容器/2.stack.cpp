#include<iostream>
#include<stack>
using namespace std;
stack<int> s;
int main(){
    int n,x;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        s.push(x);
    }
    while(s.size()){
        cout<<s.top()<<'\n';
        s.pop();
    }
    return 0;
}
