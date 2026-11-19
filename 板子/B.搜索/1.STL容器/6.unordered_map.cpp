#include<iostream>
#include<unordered_map>
using namespace std;
unordered_map<string,int> h;
int main(){
    int n,c;
    string str;
    cin>>n;
    while(n--){
        cin>>c>>str;
        if(c== 1) h[str]++;
        else{
            if(h.count(str))
                cout<<h[str]<<endl;
            else
                cout<<"No";
        }
    }
    return 0;
}