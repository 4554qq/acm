#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    char map[10][10];
    int fx,fy;
    int cx,cy;
    for(int i = 0;i<10;i++){
        for(int j = 0;j<10;j++){
            cin>>map[i][j];
            if(map[i][j] == 'F'){
                fx = i,fy = j;
            }
            else if(map[i][j] == 'C'){
                cx = i,cy = j;
            }
        }
    }
    int ans = 0;
    int fd = 0,cd = 0;
    bool zt[10][10][4][10][10][4] = {0};
    while(fx != cx || fy != cy){
        if(zt[fx][fy][fd][cx][cy][cd]){
            cout<<0;
            return 0;
        }
        zt[fx][fy][fd][cx][cy][cd] = true;
        if(fx+dx[fd] <0 || fx+dx[fd]>9 || fy+dy[fd] <0 || fy+dy[fd] >9 || map[fx+dx[fd]][fy+dy[fd]] == '*'){
            fd = (fd+1)%4;
        }
        else{
            fx = fx+dx[fd];
            fy = fy+dy[fd];
        }
        if(cx+dx[cd] < 0 || cx+dx[cd] > 9 || cy+dy[cd] < 0 || cy+dy[cd] > 9 || map[cx+dx[cd]][cy+dy[cd]] == '*'){
            cd = (cd+1)%4;
        }
        else{
            cx = cx+dx[cd];
            cy = cy+dy[cd];
        }
        ans++;
    }
    cout<<ans;
    return 0;
}
