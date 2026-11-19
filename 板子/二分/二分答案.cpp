#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+9;
int n,m;
int a[N];

bool check(int x){
  int id = 1, cnt = 1;
  for(int i=2; i<=n; i++){
    if(a[i] - a[id] >= x){
      cnt++;
      id = i;
    }
  }
  return cnt >= m;
}
int main(){
  
  cin >> n >> m;
  for(int i=1; i<=n; i++) cin >> a[i];
  sort(a+1, a+n+1);

  int l = -1, r = a[n] + 1, mid;
  while(l + 1 < r){
    mid = l + r >> 1;
    if(check(mid)) l = mid;
    else r = mid;
  }
  cout << l;
  return 0;
}