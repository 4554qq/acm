#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,c;
    cin>>n;
    vector<int> num(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>c;
        num[c] = 1;
    }
    for(int i = 1;i<=n;i++){
        if(num[i] == 0){
            cout<<i;
        }
    }
    return 0;
}