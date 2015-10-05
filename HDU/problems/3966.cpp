#pragma comment(linker,"/STACK:1024000000,1024000000")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 50010
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
 }

 void PushDown(int rt)
 {
 	tree[rt<<1].v+=tree[rt].v;
 	tree[rt<<1|1].v+=tree[rt].v;
 	tree[rt].v=0;
 }

 int t_query(int x,int rt)
 {
 	int m=(tree[rt].l+tree[rt].r)>>1;
 	if(tree[rt].l==x&&tree[rt].r==x)
 		return tree[rt].v;
 	if(tree[rt].v!=0) PushDown(rt);
 	if(x<=m) return t_query(x,rt<<1);
 	if(x>m) return t_query(x,rt<<1|1);
 }

 void t_add(int v,int l,int r,int rt)
 {
 	int m=(tree[rt].l+tree[rt].r)>>1;
 	if(tree[rt].l==l&&tree[rt].r==r){
 		tree[rt].v+=v;
 		return;
 	}
 	if(m>=r) t_add(v,l,r,rt<<1);
 	else if(m<l) t_add(v,l,r,rt<<1|1);
 	else{
 		t_add(v,l,m,rt<<1);
 		t_add(v,m+1,r,rt<<1|1);
 	}
 }

 void change(int x,int y,int v)
 {
 	int f1=top[x],f2=top[y];
 	while(f1!=f2){
 		if(deep[f1]<deep[f2]){
 			swap(f1,f2);
 			swap(x,y);
 		}
 		t_add(v,p[f1],p[x],1);
 		x=fa[f1];f1=top[x];
 	}
 	if(deep[x]>deep[y]) swap(x,y);
 	t_add(v,p[x],p[y],1);
 }

 void run()
 {
 	init();
 	int i,x,y,z;
 	char s[10];
 	for(i=1;i<=n;i++)
 		scanf("%d",&w[i]);
 	for(i=1;i<=m;i++){
 		scanf("%d%d",&x,&y);
 		addedge(x,y);
 		addedge(y,x);
 	}
 	dfs1(1,0,0);
	getpos(1,1);
	t_build(1,pos,1);
	/*
	printf("\n");
	for(i=1;i<=10;i++){
		printf("%d %d %d\n",tree[i].l,tree[i].r,tree[i].v);
	}
	for(i=1;i<=n;i++)
		printf("%d ",son[i]);
	*/
 	for(i=1;i<=q;i++){
 		scanf("%s",s);
 		if(s[0]=='Q'){
 			scanf("%d",&x);
 			printf("%d\n",t_query(p[x],1));
 		}
 		else{
 			scanf("%d%d%d",&x,&y,&z);
 			if(s[0]=='I') change(x,y,z);
 			else change(x,y,-z);
 		}
 	}
 }

int main()
{
	while(~scanf("%d%d%d",&n,&m,&q))
		run();
 return 0;
}
/*
14 13 100
1 9 7 1 13 10 8 6 2 5 11 12 3 4
1 2
1 3
1 4
2 5
2 6
3 7
4 8
4 9
4 10
6 11
6 12
9 13
13 14
*/
