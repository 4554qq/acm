//1. 领接矩阵
//二维数组w[u][v]储存从点u到点v的边的权值
//时间复杂度：O(n^2)
//空间复杂度：O(n^2)
//应用：只在点数不多的稠密图（例n = 10^3,m = 10^6）上使用
// #include<isotream>
// using namespace std;
// int w[N][N];
// int vis[N];
// void dfs(int u){
//     vis[u] = true;
//     for(int v = 1;v<=n;v++){
//         if(w[u][v]){
//             printf("%d,%d,%d\n",u,v,w[u][v]);
//             if(vis[v])    continue;
//             dfs(v);
//         }
//     }
// }
// int main(){
//     cin>>n>>m;
//     for(int i = 1;i<=m;i++){
//         cin>>a>>b>>c;
//         w[a][b] = c;
//         // w[b][a]=c;
//     }
//     dfs(1);
//     return 0;
// }

//2.边集数组
//边集数组e[i]存储第i条边的（起点u，终点v，边权w）
//时间复杂度：O（nm）
//空间复杂度：O（m）
//应用：在Kruskal算法中，束腰将边按边权排序，直接存边
// #include<iostream>
// using namespace std;
// const int M = 10086;
// const int N = 10086;
// struct edge{
//     int u,v,w;
// }e[M];//边集
// int n = 0,m = 0;
// bool vis[N];
// void dfs(int u){
//     vis[u] = true;
//     for(int i = 1;i<=m;i++){
//         if(e[i].u==u){
//             int v=e[i].v,w=e[i].w;
//             printf("%d,%d,%d\n",u,v,w);
//             if(vis[v])    continue;
//             dfs(e[i].v);
//         }
//     }
// }
// int main(){
//     int a,b,c;
//     cin>>n>>m;
//     for(int i = 1;i<=m;i++){
//         cin>>a>>b>>c;
//         e[i] = {a,b,c};
//         //e[i] = {b,a,c};
//     }
//     dfs(1);
//     return 0;
// }

//3.邻接表
//出边数组e[u][i]储存u点的所有出边的{终点v，边权w}
//时间复杂度：O(n+m)
//空间复杂度：O(n+m)
//应用：各种图，不能处理反向边
// #include<iostream>
// #include<vector>
// using namespace std;  
// const int N = 100;
// struct edge{int v,w;};
// vector<edge> e[N];
// void dfs(int u,int fa){ // 这个父节点不能处理有环图，就还是用回vis标记数组
//     for(auto ed:e[u]){
//         int v = ed.v,w = ed.w;
//         if(v==fa)continue; 
//         printf("%d %d %d\n",u,v,w);
//         dfs(v,u)   ;
//     }
// }
//   int main(){
//     int n, m; 
//     int a,b,c;
//     cin>>n>>m;
//     for(int i = 1;i<=m;i++){
//         cin>>a>>b>>c;
//         e[a].push_back({b,c});
//         e[b].push_back({a,c});
//     }
//     dfs(1,0);
//     return 0;
// }

//4链式邻接表
//边集数组e[j]存储第j条边的{起点u，终点v，边权w}
//表头数组h[u][i]存储u点的所有出边编号
//时间复杂度：O(n+m)
//空间复杂度：O(n+m)
//应用：各种图，能处理反向边
// #include<iostream>
// #include<vector>
// using namespace std;  
// const int N = 100;
// struct edge{
//     int u,v,w;
// };
// vector<edge> e;
// vector<int> h[N];

// void add(int a,int b,int c){
//     e.push_back({a,b,c});
//     h[a].push_back(e.size()-1); 
// }

// void dfs(int u,int fa){
//     for(int i = 0;i<h[u].size();i++){
//         int j = h[u][i];
//         int v = e[j].v;int w = e[j].w;
//         if(v == fa) continue;
//         cout<<u<<' '<<v<<' '<<w<<' '<<endl;
//         dfs(v,u);
//     }
// }
// int main(){
//     int n,m;
//     cin>>n>>m;
//     int a,b,c;
//     for(int i = 0;i<m;i++){
//         cin>>a>>b>>c;
//         add(a,b,c);
//         add(b,a,c);
//     }
//     dfs(1,0);
//     return 0;
// }

//5.链式前向星
//一个表头数组悬挂多个链表
//边集数组e[i]存储第i条出边的{终点v，边权w，下一条边ne}
//表头数组h[u]存储u点的第一条出边的编号
//边的编号idx可取0，1，2，3...
//时间复杂度：O(n+m)
//空间复杂度：O(n+m)
//应用：各种图，能处理反向边
#include<iostream>
#include<vector>
using namespace std;

const int N = 29;
const int M = 59;

struct edge{
    int v,w,ne;
};
int h[N],idx;
edge e[M];

void add(int a,int b,int c){
    e[idx] = {b,c,h[a]};
    h[a] = idx++;
}

void dfs(int u,int fa){
    for(int i = h[u];~i;i = e[i].ne){
        int v = e[i].v, w = e[i].w;
        if(v == fa) continue;
        cout<<u<<' '<<v<<' '<<w<<'\n';
        dfs(v,u);
    }
}

int main(){
    int n,m,a,b,c;
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i = 1;i<=m;i++){
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }
    dfs(1,0);
    return 0;
}

   

