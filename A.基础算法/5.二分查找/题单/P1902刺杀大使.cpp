// #include<bits/stdc++.h>
// using namespace std;
// int m,n;
// int dx[] = {-1,0,1,0},dy[] = {0,1,0,-1};
// vector<vector<int>> p;
// vector<vector<int   >> vis;
// bool dfs(int x,int y ,int P){
//     if(p[x][y]>P)   return false;
//     if(x == n-1)  return true;
//     vis[x][y]=true;
//     for(int i = 0;i<4;i++){
//         int a = x+dx[i],b=y+dy[i];
//         if(a>=0&&a<n&&b>=0&&b<m&&!vis[a][b])
//             if(dfs(a,b,P))  return true;
//     }
//     return false;
// }
// int solve_find()
// {
//     int l = -1,r = 1001;
//     while(l+1<r){
//         int mid = l+r>>1;
//         for(auto& row :vis) fill(row.begin(),row.end(),0);
//         if(dfs(0,0,mid))   r = mid;
//         else    l = mid;
//     }
//     return r;
// }

// int main()
// {
//     cin>>n>>m;
//     p.resize(n,vector<int>(m));
//     vis.resize(n,vector<int>(m));
//     for(int i = 0;i<n;i++)
//     for(int j = 0;j<m;j++)
//         cin>>p[i][j];
//     cout<<solve_find();
//     return 0;
// }

#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int p[1002][1002];
bool vis[1002][1002];
int n, m;
int xi[] = { 0,1,0,-1 }, yi[] = {1,0,-1,0};
bool dfs(int x, int y, int P) {
	if (p[x][y] > P)	return false;
	if (x == n)	return true;
	vis[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int a = x + xi[i], b = y + yi[i];
		if (a >= 1 && a <= n && b >= 1 && b <= m && !vis[a][b]) {
			if (dfs(a, b, P))	return true;
		}
	}
	return false;
}
int solve_find() {
	int l = -1, r = 1001;
	while (l + 1 < r) {
		int mid = l + r >> 1;
		memset(vis,0,sizeof(vis));
		if (dfs(1, 1, mid))	r = mid;
		else l = mid;
	}
	return r;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) 
			cin >> p[i][j];
	cout<<solve_find();
	return 0;
}