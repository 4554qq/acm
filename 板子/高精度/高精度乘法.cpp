// #include<bits/stdc++.h>
// using namespace std;

// int A[4060],B[4060],C[8120];
// int la,lb,lc;
// void mul(int A[],int B[],int C[]){
//     for(int i = 0;i<la;i++){
//         for(int j = 0;j<lb;j++){
//             C[i+j] += A[i]*B[j];
//             C[i+j+1] += C[i+j]/10;
//             C[i+j] = C[i+j]%10;
//         }
//     }
//     while(lc&&!C[lc])   lc--;
// }
// int main(){
//     string a,b;
//     cin>>a>>b;
//     la = a.size(),lb = b.size(),lc = la+lb;
//     for(int i = la-1;~i;i--)    A[i] = a[la-i-1]-'0';
//     for(int i = lb-1;~i;i--)    B[i] = b[lb-i-1]-'0';
//     mul(A,B,C);
//     for(int i  = lc;~i;i--) cout<<C[i];
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
VI A,B;
void mul(VI &A,VI &B,VI &C){
    for(int i = 0;i<A.size();i++){
        for(int j = 0;j<B.size();j++){
            C[i+j] += A[i]*B[j];
            C[i+j+1] += C[i+j]/10;
            C[i+j] = C[i+j]%10;
        }
    }
    while(C.size()>1&&!C.back())   C.pop_back();
}
int main(){
    string a,b;
    cin>>a>>b;
    for(int i = a.size()-1;~i;i--)    A.push_back(a[i]-'0');
    for(int i = b.size()-1;~i;i--)    B.push_back(b[i]-'0');
    VI C(a.size()+b.size());
    mul(A,B,C);
    for(int i  = C.size()-1;~i;i--) cout<<C[i];
    return 0;
}