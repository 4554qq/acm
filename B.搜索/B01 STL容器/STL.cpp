//vector-动态数组
// #include<iostream>
// #include<cstring>
// #include<algorithm>
// #include<vector>
// using namespace std;
// vector<int> v;
// int main()
// {
//     int x,n;
//     cin>>n;
//     for(int i = 0;i<n;i++){
//         cin>>x;
//         v.push_back(x);
//     }
//     for(int i = 0;i<v.size();i++)   cout<<v[i]<<' ';
//     puts("");
//     sort(v.begin(),v.end());
//     for(int e:v)    cout<<e<<' ';
//     puts("");
//     reverse(v.begin(),v.end());
//     for(int e:v)cout<<e<<' ';
//     return 0;
// }

//stack-栈
// #include<iostream>
// #include<stack>
// using namespace std;
// stack<int> s;
// int main(){
//     int n,x;
//     cin>>n;
//     for(int i = 1;i<=n;i++){
//         cin>>x;
//         s.push(x);
//     }
//     while(s.size()){
//         cout<<s.top()<<'\n';
//         s.pop();
//     }
// }
// #include<iostream>
// using namespace std;
// int s [10000],top;
// int main(){
//     int n,x;
//     cin>>n;
//     for(int i = 1;i<=n;i++){
//         cin>>x;
//         s[++top] = x;
//     }
//     while(top){
//         cout<<s[top]<<' ';
//         top--;
//     }
// }

//queue-队列
// #include<iostream>
// #include<queue>
// using namespace std;
// const int N = 10086;
// vector<int> e[N];
// int vis[N];
// queue<int> q;
// void bfs(){
//     vis[1] = 1;q.push(1);
//     while(q.size()){
//         int x = q.front();
//         q.pop();
//         cout<<x<<endl;
//     for(auto y:e[x]){
//         if(vis[y])  continue;
//         vis[y] = 1;
//         q.push(y);
//     }
// }
// }
// int main(){
//     int n,m,a,b;
//     cin>>n>>m;
//     for(int i =0;i<m;i++){
//         cin>>a>>b;
//         e[a].push_back(b);
//         e[b].push_back(a);
//     }
//     bfs();
// }

//priority_queue-优先队列
// #include<iostream>
// #include<queue>
// using namespace std;
// const int N = 100010;
// int n,m,s,a,b,c;
// struct edge{
//     int v,w;
// };
// vector<edge> e[N];
// int d[N],vis[N];
// priority_queue<pair<int,int>> q;
// void dijkstra(){
//     for(int i=0;i<=n;i++)   d[i]=1e9;
//     d[1]=0;
//     q.push({0,1});
//     while(q.size()){
//         auto t=q.top();
//         q.pop();
//         int u=t.second;
//         if(vis[u])  continue;
//         vis[u]=1;
//         for(auto ed:e[u]){
//             int v=ed.v,w=ed.w;
//             if(d[v]>d[u]+w){
//                 d[v]=d[u]+w;
//                 q.push({-d[v],v});
//             }
//         }
//     }
// }

//unordered_set-无序队列
// #include<iostream>
// #include<unordered_set>
// using namespace std;
// unordered_set<int> s;
// int main(){
//     int n,c,x;
//     cin>>n;
//     while(n--){
//         cin>>c>>x;
//         if(c==1) s.insert(x);//ifc==1向s中插入一个x
//         else    s.count(x)?puts("Yes"):puts("No");//如果s中有x则输出yes
//     }
// }

//unordered_map-无序键值对映射
// #include<iostream>
// #include<unordered_map>
// using namespace std;
// unordered_map<string,int> h;
// int main(){
//     int n,c;
//     string str;
//     cin>>n;
//     while(n--){
//         cin>>c>>str;
//         if(c==1) h[str]++;
//         else{
//             if(h.count(str))
//                 printf("%d\n",h[str]);
//             else
//                 puts("No");
//         }
//     }
// }



