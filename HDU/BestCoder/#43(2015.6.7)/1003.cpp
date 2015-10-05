#pragma comment(linker,"/STACK:1024000000,1024000000")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define NMAX 300010
using namespace std;
struct node{
	int to,next;
}edge[NMAX<<1];
struct SegTree{
	int l,r,f; 
}tree[NMAX<<2];
int n,tot,fa[NMAX],deep[NMAX],head[NMAX];

void init()
{
	memset(head,-1,sizeof(head));
	tot=0;
}

void addedge(int x,int y)
{
	++tot;
	edge[tot].next=head[x];
	edge[tot].to=y;
	head[x]=tot;
}

void DFS(int x,int pre,int dp)
{
	int i,p;
	fa[x]=pre;
	deep[x]=dp;
	for(i=head[x];i!=-1;i=edge[i].next){
		p=edge[i].to;
		if(p!=pre){
			DFS(p,x,dp+1);
		}
	}
}

int find(int f1,int f2)
{
	if(deep[f1]<deep[f2]) swap(f1,f2);
	if(f2==1) return 1;
	while(deep[f1]>deep[f2]) f1=fa[f1];
	while(f1!=f2){
		f1=fa[f1];
		f2=fa[f2];
	}
	return f1;
}

void t_build(int l,int r,int rt)
{
	int m=(l+r)>>1;
	tree[rt].l=l;tree[rt].r=r;
	if(l==r){
		tree[rt].f=l;
		return;
	}
	t_build(l,m,rt<<1);
	t_build(m+1,r,rt<<1|1);
	tree[rt].f=find(tree[rt<<1].f,tree[rt<<1|1].f);
}

int t_query(int l,int r,int rt)
{
	int m=(tree[rt].l+tree[rt].r)>>1;
	if(l==tree[rt].l&&r==tree[rt].r)
		return tree[rt].f;
	if(m>=r) return t_query(l,r,rt<<1);
	if(m<l) return t_query(l,r,rt<<1|1);
	return find(t_query(l,m,rt<<1),t_query(m+1,r,rt<<1|1));
}

void fuck()
{
	int i,q,x,y;
	init();
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	DFS(1,0,1);
	/*for(i=1;i<=n;i++){
		printf("%d %d\n",fa[i],deep[i]);
	}*/
	t_build(1,n,1);
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&x,&y);
		if(x>y) swap(x,y);
		printf("%d\n",t_query(x,y,1));
	}
}
int main()
{
	while(~scanf("%d",&n)){
		fuck();	
	}
 return 0;
}

