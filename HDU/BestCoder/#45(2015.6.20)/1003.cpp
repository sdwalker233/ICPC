#pragma comment(linker,"/STACK:1024000000,1024000000")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 100010
using namespace std;
struct node{
    int to,next;
}edge[MAXN*2];
struct SegTree{
    int l,r,v;
}tree[MAXN*10];
int head[MAXN],tot,pos;
int son[MAXN],top[MAXN],deep[MAXN],fa[MAXN],p[MAXN],fp[MAXN],num[MAXN];
int n,m,q,w[MAXN];

 void init()
 {
    tot=0;pos=0;
    memset(head,-1,sizeof(head));
    memset(son,-1,sizeof(son));
 }

 void addedge(int u,int v)
 {
     ++tot;
     edge[tot].to=v;
     edge[tot].next=head[u];
     head[u]=tot;
 }

 void dfs1(int x,int pre,int d)
 {
     int i,v;
     fa[x]=pre;
     deep[x]=d;
     num[x]=1;
     for(i=head[x];i!=-1;i=edge[i].next){
         v=edge[i].to;
         if(v==pre) continue;
         dfs1(v,x,d+1);
         num[x]+=num[v];
         if(son[x]==-1||num[v]>num[son[x]])
             son[x]=v;
     }
 }

 void getpos(int x,int tp)
 {
     int i,v;
     ++pos;
     top[x]=tp;
     p[x]=pos;
     fp[pos]=x;
     if(son[x]==-1) return;
     getpos(son[x],tp);
     for(i=head[x];i!=-1;i=edge[i].next){
         v=edge[i].to;
         if(v!=son[x]&&v!=fa[x])
             getpos(v,v);
     }
 }

 void t_build(int l,int r,int rt)
 {
     int m=(l+r)>>1;
     tree[rt].l=l;tree[rt].r=r;tree[rt].v=0;
     if(l==r){
         tree[rt].v=w[fp[l]];
         return;
     }
     t_build(l,m,rt<<1);
     t_build(m+1,r,rt<<1|1);
     tree[rt].v=(tree[rt<<1].v^tree[rt<<1|1].v);
 }

 void t_change(int v,int x,int rt)
 {
     int m=(tree[rt].l+tree[rt].r)>>1;
     tree[rt].v=(tree[rt].v^w[fp[x]]);
     tree[rt].v=(tree[rt].v^v);
     if(tree[rt].l==x&&tree[rt].r==x) return;
     if(x<=m) t_change(v,x,rt<<1);
     if(x>m) t_change(v,x,rt<<1|1);
 }

 int t_query(int l,int r,int rt)
 {
     int m=(tree[rt].l+tree[rt].r)>>1;
     if(tree[rt].l==l&&tree[rt].r==r) return tree[rt].v;
     if(m>=r) return t_query(l,r,rt<<1);
     if(m<l) t_query(l,r,rt<<1|1);
     return t_query(l,m,rt<<1)^t_query(m+1,r,rt<<1|1);
 }

 int f(int x,int y)
 {
     int f1=top[x],f2=top[y],res=0;
     while(f1!=f2){
         if(deep[f1]<deep[f2]){
             swap(f1,f2);
             swap(x,y);
         }
         res^=t_query(p[f1],p[x],1);
         x=fa[f1];f1=top[x];
     }
     if(deep[x]>deep[y]) swap(x,y);
     res^=t_query(p[x],p[y],1);
     return res-1;
 }

 void run()
 {
     init();
     int i,x,y,z;
     scanf("%d%d",&n,&q);
     for(i=1;i<n;i++){
         scanf("%d%d",&x,&y);
         addedge(x,y);
         addedge(y,x);
     }
     for(i=1;i<=n;i++){
     	scanf("%d",&w[i]);
     	w[i]++;
	 }
     dfs1(1,0,0);
     getpos(1,1);
     t_build(1,pos,1);
     for(i=1;i<=q;i++){
         scanf("%d%d%d",&z,&x,&y);
         if(z==1){
             printf("%d\n",f(x,y));
         }
         else{
             t_change(y,x,1);
             w[x]=y;
         }
     }
 }

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		run(); 
 return 0;
}
