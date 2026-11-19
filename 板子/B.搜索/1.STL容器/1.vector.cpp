// #include<iostream>
// #include<algorithm>
// #include<vector>
// using namespace std;
// vector<int> v;
// int main(){
//     int n,x;
//     cin>>n;
//     for(int i =0;i<n;i++){
//         cin>>x;
//         v.push_back(x);
//     }
//     for(int i = 0;i<v.size();i++){
//         cout<<v[i]<<' ';
//     }
//     puts("");
//     sort(v.begin(),v.end());
//     for(int e:v) cout<<e<<' ';
//     return 0;
// }

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct edge{
    int u,v,w;
    bool operator<(const edge &t) const
    {return w<t.w;}
};
vector<edge> es;//边集
int main(){
    int m,a,b,c;
    cin>>m;
    for(int i = 1;i<=m;i++){
        cin>>a>>b>>c;
        es.push_back({a,b,c});
    }
    sort(es.begin(),es.end());
    for(int i =0 ;i<es.size();i++){
        cout<<es[i].u<<' '<<es[i].v<<' '<<es[i].w<<endl;
    }
    return 0;
}
