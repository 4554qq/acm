#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> xs(n+1,0);
    int num = 0;
    if(n == 0){
        cin>>num;
        cout<<num;
        return 0;
    }
    int shou = 0;
    for(int i = 0;i<=n;i++){
        cin>>num;
        if(i == 0){
            if(n != 1){
                if(num == 0){
                    continue;
                }
                if(num == 1){
                    cout <<"x^"<<n-i;
                    shou = 1;
                }
                else if(num == -1){
                    cout<< "-x^"<<n-i;
                }
                else{
                    cout<< num << "x^"<<n-i;
                }
            }

            else{
                if(num == 0){   
                    continue;
                }
                if(num == 1){
                    cout <<"x";
                }
                else if(num == -1){
                    cout<< "-x";
                }
                else{
                    cout<< num << "x";
                }
            }
            shou = 1; 
        }

        else if(i>0&&i<n-1){
            if(num == 0){
                continue;
                }
            if(num == 1){
                if(shou){
                    cout<<'+';
                }
                cout <<"x^"<<n-i;
                shou = 1;
            }
            else if(num == -1){
                cout<< "-x^"<<n-i;
                shou =1;
            }
            else{
                if(num>0){
                    if(shou)
                    cout<<'+';
                }
                cout<< num << "x^"<<n-i;
                shou = 1;
            }
        }
        else if(i == n-1){
            if(num == 0){
                continue;
            }
            if(num == 1){
                if(shou){
                    cout<<'+';
                }
                cout <<"x";
                shou = 1;
            }
            else if(num == -1){
                cout<< "-x";
                shou = 1;
            }
            else{
                if(num>0)
                cout<<'+';
                cout<< num << "x";
                shou = 1;
            }
        }
        else{//常数
            if(num == 0){
                if(shou == 0){
                    cout<< '0';
                }
                continue;
            }
            if(num>=0)
            cout<<'+';
            cout<<num;
        }
    }
    return 0;
}