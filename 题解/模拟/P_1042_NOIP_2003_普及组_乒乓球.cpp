#include<bits/stdc++.h>
using namespace std;
string s;
void solve(){
    int i = 0;
    int h = 0;
    int d = 0;
    int hj = 0,dj = 0;
    while (i<s.length()){
        if(s[i] == 'W'){
            h++;
        }
        else{
            d++;
        }
        i++;
        if(h >= 11&&h-d >=2){
            hj++;
            cout<<h<<':'<<d<<'\n';
            h = 0;
            d = 0;
        }
        else if(d >= 11&& d-h>=2){
            dj++;
            cout<<h<<':'<<d<<'\n';
            h = 0;
            d = 0;
        }
    }
    cout<<h<<':'<<d<<'\n';
}
void solve1(){
    int i = 0;
    int h = 0;
    int d = 0;
    int hj = 0,dj = 0;
    while (i<s.length()){
        if(s[i] == 'W'){
            h++;
        }
        else{
            d++;
        }
        i++;
        if(h >= 21&&h-d >=2){
            hj++;
            cout<<h<<':'<<d<<'\n';
            h = 0;
            d = 0;
        }
        else if(d >= 21&& d-h>=2){
            dj++;
            cout<<h<<':'<<d<<'\n';
            h = 0;
            d = 0;
        }
    }
    cout<<h<<':'<<d<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    char c;
    while (cin >> c && c != 'E') {
        s += c;
    }
    solve();
    cout<<'\n';
    solve1();
    return 0;
}