#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cctype>

using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int p1 ,p2 ,p3 ;
    cin>>p1>>p2>>p3;
    string s;
    cin>>s;
    for(int i = 1;i<s.size();i++){
        if(s[i] == '-'){
            char a = s[i-1];
            char b = s[i+1];
            int flag = 0;
            if((a>='0'&&a<='9')^(b>='0'&&b<='9')){
                continue;
            }
            if((a>='a'&&a<='z')^(b>='a'&&b<='z')){
                continue;
            }
            if(a>='0'&&a<='9'&&b>='0'&&b<='9'){
                flag = 1;
            }
            int len = b-a-1;
            if(len<0) continue;
            s.erase(i,1);
            while(len--){
                if(p1 == 1){
                    if(p3 == 1){
                        s.insert(i,p2,len+a+1);
                    }
                    else{
                        s.insert(i,p2,b-len-1);
                    }
                }
                else if(p1 == 2){
                    if(flag){    
                        if(p3 == 1){
                            s.insert(i,p2,len+a+1);
                        }
                        else{
                            s.insert(i,p2,b-len-1);
                        }
                    }
                    else{    
                        if(p3 == 1){
                            s.insert(i,p2,len+a+1-32);
                        }
                        else{
                            s.insert(i,p2,b-len-32-1);
                        }
                    }
                }
                else{
                    s.insert(i,p2,'*');
                }
            }
            i+=((b-a-1)*p2)-1;
        }
    }
    cout<<s;
    return 0;
}