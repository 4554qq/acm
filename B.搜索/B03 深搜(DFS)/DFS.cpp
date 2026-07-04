//1.深搜的过程
//根进入，向下走，走到底，向上走，即绕树兜圈子，最后从根退出。
//2.深搜的实现
//深搜是通过系统栈实现的。
//递归调用的过程，系统自动通过栈过去维护函数的状态空间。
//系统栈记录函数返回地址、局部变量、参数传递等。
//向下走，压栈；向上走弹栈。
//3.深搜的计算
//触碰节点的时机：
//1.入，2.下，3.回，4.离。
//多次触碰同一个节点的状态空间。自顶向下（父算子1，2）自底向上（子算父3，4）。
// #include<iostream>
// #include<vector>
// using namespace std;
// const int N = 1e2+9;
// vector<int> e[N];
// void dfs(int u,int fa){
//     for(auto v:e[u]){
//         if(v == fa) continue;
//         printf("%d %d\n",u,v);
//         dfs(v,u);
//     }
// }
// int main(){
//     int n,m,a,b;
//     cin>>n>>m;
//     for(int i = 1;i<=m;i++){
//         cin>>a>>b;
//         e[a].push_back(b);
//         e[b].push_back(a);
//     }
//     dfs(1,0);
//     return 0;
// }


