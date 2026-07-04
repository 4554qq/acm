#include<iostream>
using namespace std;
#define N 50005
#define lc p<<1
#define rc p<<1|1
int n,num[N];
struct node{
    int l;int r;int sum;int add; 
}tr[4*N];
void build(int p,int l,int r){
    tr[p] = {l,r,num[l]};
    if(l == r) return ;
    int m = (l+r>>1);
    build(lc,l,m);
    build(rc,m+1,r);
    tr[p].sum = tr[lc].sum+tr[rc].sum;
}

void pushup(int p){
    tr[p].sum = tr[lc].sum+tr[rc].sum;    
}
void pushdown(int p){
    if(tr[p].add){
        tr[lc].sum += tr[p].add*(tr[lc].r-tr[lc].l+1);
        tr[rc].sum += tr[p].add*(tr[rc].r-tr[rc].l+1);
        tr[lc].add += tr[p].add;
        tr[rc].add += tr[p].add;
        tr[p].add = 0;
    }
}
void update1(int p,int x,int y,int k){
    if(tr[p].l > y || tr[p].r < x) return;
    if(x<=tr[p].l&&tr[p].r<=y){
        tr[p].sum+=(tr[p].r-tr[p].l+1)*k;
        tr[p].add+=k;
        return ;
    }
    pushdown(p);
    update1(lc,x,y,k);
    update1(rc,x,y,k);
    pushup(p);
}
void update(int p,int x,int k){
    pushdown(p);
    if(tr[p].l == x&& tr[p].r == x){
        tr[p].sum+=k;
        return ;
    }
    int m = tr[p].l+tr[p].r>>1;
    if(x<=m) update(lc,x,k);
    else    update(rc,x,k);
    pushup(p);
}

int quary(int p,int x,int y){
    if(x<=tr[p].l&&tr[p].r<=y)  return tr[p].sum;
    int m = tr[p].l+tr[p].r>>1;
    int sum = 0;
    if(x<=m) sum+=quary(lc,x,y);
    if(y>m)     sum+=quary(rc,x,y);
    return sum;
}

int main(){
    cin>>n;
    for(int i = 1;i<=n;i++) cin>>num[i];
    build(1,1,n);
    for(int i = 1;i<=4*n;i++) cout<<tr[i].sum<<endl;
    return 0;
}