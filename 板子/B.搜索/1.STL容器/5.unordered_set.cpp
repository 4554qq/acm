#include<iostream>
#include<unordered_set>
using namespace std;
unordered_set<int> s;
int main(){
    int n,c,x;
    cin>>n;
    while(n--){
        cin>>c>>x;
        if(c == 1) s.insert(x);
        else
            s.count(x)?puts("Yes"):puts("No");
    }
    return 0;
}