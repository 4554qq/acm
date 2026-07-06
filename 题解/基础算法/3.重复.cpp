#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n = s.size();
    int len = 1;
    int maxl = 0;
    for(int i = 1;i<=n;i++){
        maxl = max(maxl,len); 
        if(s[i] == s[i-1]){
            len++;
        }
        else{
            len = 1;
        }
    }
    cout<<maxl;
    return 0;
}