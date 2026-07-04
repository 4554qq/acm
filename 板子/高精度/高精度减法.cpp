
#include<bits/stdc++.h>
#define MAXN 10500
using namespace std;
int A[MAXN],B[MAXN],C[MAXN];
int la,lb,lc;
bool cmp(int A[],int B[]){
  if(la!=lb)  return la>lb;
  for(int i = la-1;~i;i--)
    if(A[i]!=B[i])  
      return A[i]>B[i];
  return true;
}
void sub(int A[],int B[],int C[]){
  for(int i = 0;i<lc;i++){
    if(A[i]<B[i]){
      A[i]+=10;
      A[i+1]--;
    }
    C[i] = A[i]-B[i];
  }
  while(lc&&!C[lc]) lc--;
}
int main()
{
	string a, b;
	cin >> a >> b;
  la = a.size(),lb = b.size(),lc = max(a.size(),b.size());
  for (int i = 0;i < a.size();i++)	A[i] = a[a.size()-i-1] - '0';
	for (int i = 0;i < b.size();i++)  B[i] = b[b.size()-i-1] - '0';
  if(!cmp(A,B)) swap(A,B),cout<<'-';
  sub(A,B,C);
	for(int i = lc;~i;i--)
	{
		cout << C[i];
	}
	return 0;
}
/*2.
#include<bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
VI A,B,C;
bool cmp(VI &A,VI &B){
    if(B.size()!=A.size())  return A.size()>B.size();
    for(int i = A.size()-1;~i;i--)
    if(A[i]!=B[i])  return A[i]>B[i];
    return true;//避免-0情况
}
void sub(VI &A,VI &B,VI &C){
  int t = 0;
  for(int i = 0;i<A.size();i++){
    t = A[i];
    if(i<B.size())  t-=B[i];
    if(t<0) t+=10,A[i+1]--;
    C.push_back(t);
  }
    while(C.size()>1&&!C.back())  C.pop_back();
}
int main()
{
    string a,b;
    cin>>a>>b;
    for(int i = a.size()-1;~i;i--)    A.push_back(a[i]-'0');
    for(int i = b.size()-1;~i;i--)    B.push_back(b[i]-'0');
    if(!cmp(A,B))   swap(A,B),cout<<'-';
    sub(A,B,C);
    for(int i  = C.size()-1;~i;i--)   cout<<C[i];
    return 0;
}
*/