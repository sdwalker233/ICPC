#include<bits/stdc++.h>
#define MAXN 200010
using namespace std;
struct node{
	int to,next;
}edge[MAXN<<1];
struct SegTree{
	int l,r,mx;
}tree[MAXN<<2];
struct node2{
	int x,y,v,index;
	friend bool operator<(const node2& a,const node2& b){
		return a.v<b.v;
	}
}e[MAXN<<1],e2[MAXN<<1];

long long sumv;
int n,m,fa1[MAXN],tot,head[MAXN],pos;
int son[MAXN],top[MAXN],deep[MAXN],fa[MAXN],p[MAXN],fp[MAXN],num[MAXN];

 void init()
 {
 	tot=0;pos=0;
 	memset(head,-1,sizeof(head));
	memset(son,-1,sizeof(son));
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
		 if(son[v]==-1||num[v]>num[son[x]])
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
	 tree[rt].l=l;tree[rt].r=r;tree[rt].mx=0;
	 if(l==r) return;
	 t_build(l,m,rt<<1);
	 t_build(m+1,r,rt<<1|1);
 }

 void t_update(int x,int v,int rt)
 {
	 int m=(tree[rt].l+tree[rt].r)>>1;
	 if(tree[rt].l==x&&tree[rt].r==x){
		 tree[rt].mx=v;
		 return;
	 }
	 if(x<=m) t_update(x,v,rt<<1);
	 else t_update(x,v,rt<<1|1);
	 tree[rt].mx=max(tree[rt<<1].mx,tree[rt<<1|1].mx);
 }

 int t_query(int l,int r,int rt)
 {
	 int m=(tree[rt].l+tree[rt].r)>>1;
	 if(l==tree[rt].l&&r==tree[rt].r) return tree[rt].mx;
	 if(m>=r) return t_query(l,r,rt<<1);
	 if(m<l) return t_query(l,r,rt<<1|1);
	 return max(t_query(l,m,rt<<1),t_query(m+1,r,rt<<1|1));
 }

 int t_find(int x,int y)
 {
	 int f1=top[x],f2=top[y],tmp=0;
	 while(f1!=f2){
		 //printf("%d %d\n",f1,f2);
		 if(deep[f1]<deep[f2]){
			 swap(f1,f2);
			 swap(x,y);
		 }
		 tmp=max(tmp,t_query(p[f1],p[x],1));
		 x=fa[f1];f1=top[x];
	 }
	 if(x==y) return tmp;
	 if(deep[x]>deep[y]) swap(x,y);
	 //printf("%d %d\n",p[son[x]],p[y]);
	 return max(tmp,t_query(p[son[x]],p[y],1));
 }

void addedge(int x,int y)
{
	++tot;
	edge[tot].to=y;
	edge[tot].next=head[x];
	head[x]=tot;
}

int find(int x)
{
	if(fa1[x]==x) return x;
	return fa1[x]=find(fa1[x]);
}

void unio(int x,int y)
{
	fa1[find(x)]=find(y);
}

void MST()
{
	int i,fx,fy,cnt=0;
	sumv=0;
	sort(e+1,e+1+m);
	for(i=1;i<=m;i++){
		fx=find(e[i].x);
		fy=find(e[i].y);
		if(fx!=fy){
			addedge(e[i].x,e[i].y);
			addedge(e[i].y,e[i].x);
			unio(fx,fy);
			++cnt;
			e2[cnt].x=e[i].x;e2[cnt].y=e[i].y;e2[cnt].v=e[i].v;
			sumv+=e[i].v;
		}
		if(cnt==n-1) break;
	}
	//cout<<sumv<<endl;
}

bool cmp(const node2& a,const node2& b)
{
	return a.index<b.index;
}

int main()
{
	int i,v;
	init();
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].v);
		e[i].index=i;
	}
	for(i=1;i<=n;i++) fa1[i]=i;
	MST();
	dfs1(1,0,0);
	getpos(1,1);
	t_build(1,pos,1);
	for(i=1;i<n;i++){
		if(deep[e2[i].x]>deep[e2[i].y]) swap(e2[i].x,e2[i].y);
		t_update(p[e2[i].y],e2[i].v,1);
	}
	sort(e+1,e+m+1,cmp);
	for(i=1;i<=m;i++){
		printf("%I64d\n",sumv+e[i].v-t_find(e[i].x,e[i].y));
		//printf("%d\n",t_find(e[i].x,e[i].y));
	}
 return 0;
}
