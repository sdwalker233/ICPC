#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 100010
using namespace std;
struct node{
	int to,next;
}edge[MAXN<<1];
struct Segtree{
	int l,r,pos;
	long long mx,de;
}tree[MAXN<<2];
int head[MAXN],fa[MAXN],t1[MAXN],t2[MAXN],ft[MAXN];
long long sumw[MAXN],w[MAXN];
int tot,num;
bool visit[MAXN];

 void init()
 {
 	tot=0;num=0;
 	memset(head,-1,sizeof(head));
 	memset(sumw,0,sizeof(sumw));
 	memset(visit,0,sizeof(visit));
 }

 void addedge(int x,int y)
 {
 	tot++;
 	edge[tot].to=y;
 	edge[tot].next=head[x];
 	head[x]=tot;
 }

 void DFS(int x,int pre)
 {
 	int i,d;
 	sumw[x]=sumw[pre]+w[x];
 	t1[x]=++num;
 	ft[num]=x;
 	fa[x]=pre;
 	for(i=head[x];i!=-1;i=edge[i].next){
 		d=edge[i].to;
 		if(d!=pre){
 			DFS(d,x);
 		}
 	}
 	t2[x]=num;
 }

 void PushDown(int rt)
 {
 	if(tree[rt].de){
 		tree[rt<<1].de+=tree[rt].de;
 		tree[rt<<1|1].de+=tree[rt].de;
 		tree[rt].de=0;
 	}
 }

 void PushUp(int rt)
 {
 	if(tree[rt<<1].mx>tree[rt<<1|1].mx){
 		tree[rt].mx=tree[rt<<1].mx;
 		tree[rt].pos=tree[rt<<1].pos;
 	}
 	else{
 		tree[rt].mx=tree[rt<<1|1].mx;
 		tree[rt].pos=tree[rt<<1|1].pos;
 	}
 }

 void t_build(int l,int r,int rt)
 {
 	int m=(l+r)>>1;
 	tree[rt].l=l;tree[rt].r=r;tree[rt].de=0;
 	if(l==r){
 		tree[rt].mx=sumw[ft[l]];
		tree[rt].pos=ft[l];
 		return;
 	}
 	t_build(l,m,rt<<1);
 	t_build(m+1,r,rt<<1|1);
 	PushUp(rt);
 }

 void t_decrease(long long v,int l,int r,int rt)
 {
 	int m=(tree[rt].l+tree[rt].r)>>1;
 	if(l==tree[rt].l&&r==tree[rt].r){
 		tree[rt].de+=v;
 		tree[rt].mx-=v;
 		return;
 	}
 	PushDown(rt);
 	if(m>=r) t_decrease(v,l,r,rt<<1);
 	else if(m<l) t_decrease(v,l,r,rt<<1|1);
 	else{
 		t_decrease(v,l,m,rt<<1);
 		t_decrease(v,m+1,r,rt<<1|1);
 	}
 	PushUp(rt);
 }

 void fuck()
 {
 	int i,j,n,k,x,y;
 	long long ans=0;
 	init();
 	scanf("%d%d",&n,&k);
 	for(i=1;i<=n;i++){
 		scanf("%lld",&w[i]);
 	}
 	for(i=1;i<n;i++){
 		scanf("%d%d",&x,&y);
 		addedge(x,y);
 		addedge(y,x);
 	}
 	DFS(1,0);
 	/*for(i=1;i<=n;i++)
 		printf(" %d %d %lld\n",t1[i],t2[i],sumw[i]);*/
 	t_build(1,n,1);
 	for(i=1;i<=k;i++){
 		printf(" %lld\n",tree[1].mx);
 		ans+=tree[1].mx;
 		for(j=tree[1].pos;j;j=fa[j])
 			if(!visit[j]){
 				printf("   %d\n",j);
 				t_decrease(w[j],t1[j],t2[j],1);
 				visit[j]=1;
 			}
 	}
 	printf("%lld\n",ans);
 }

int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		printf("Case #%d: ",i);
		fuck();
	}
 return 0;
}
/*
100
12 3
1 2 3 4 5 6 7 8 9 10 11 12
1 2
1 3
2 4
3 5
3 6
4 7
4 8
5 9
5 10
6 11
7 12
*/
