// #include<bits/stdc++.h>
// #define MAX 10500
// using namespace std;
// int A[MAX],C[MAX];
// int b,la,lc;
// void div(int A[],int b,int C[]){
//     long long t = 0;
//     for(int i = la-1;~i;i--){
//         t= t*10+A[i];
//         C[i] = t/b;
//         t%=b;
//     }
//     while(lc&&C[lc] == 0)   lc--;
// }
// int main(){
//     string a;
//     cin>>a>>b;
//     lc = la = a.size();
//     for(int i = a.size()-1;~i;i--)    A[la-i-1] = a[i]-'0';
//     //for(int i = a.size()-1;~i;i--)    A[i] = a[i];
//     div(A,b,C);
//     for(int i = lc;~i;i--)  cout<<C[i];
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
VI A,C;
int b;
void div(VI &A,int b,VI &C){
    long long t = 0;
    for(int i = A.size()-1;~i;i--){
        t= t*10+A[i];
        C.push_back(t/b);
        t%=b;
    }
    reverse(C.begin(),C.end());
    while(C.size()>1&&!C.back())   C.pop_back();
}
int main(){
    string a;
    cin>>a>>b;
    for(int i = a.size()-1;~i;i--)    A.push_back(a[i]-'0');
    div(A,b,C);
    for(int i = C.size()-1;~i;i--)  cout<<C[i];
    return 0;
}