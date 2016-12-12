#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
using namespace std;
struct zxTree{
	int l,r,v;
}tree[MAXN<<4];
int n,m,t,T_cnt;
int a[MAXN],b[MAXN],root[MAXN];

int get_pos(int x)
{
	return lower_bound(b+1,b+t+1,x)-b-1;
}

int t_update(int v,int pos,int l,int r,int rt)
{
	root[pos]=++T_cnt;
	int nrt=T_cnt;
	tree[nrt].v=tree[rt].v+v;
	if(l==r) return nrt;
	int m=(l+r)>>1;
	if(pos<=m){
		tree[nrt].l=t_update(v,pos,l,m,tree[rt].l);
		tree[nrt].r=tree[rt].r;
	}
	else{
		tree[nrt].l=tree[rt].l;
		tree[nrt].r=t_update(v,pos,m+1,r,tree[rt].r);
	}
	printf(" %d %d %d\n",nrt,tree[nrt].l,tree[nrt].r);
	return nrt;
}

int t_query(int l,int r,int lroot,int rroot,int k)
{
	int m=(l+r)>>1;
	if(l==r) return l;
	if(tree[rroot].v-tree[lroot].v>=k){
		return t_query(l,m,tree[lroot].l,tree[rroot].l,k);
	}
	else{
		return t_query(m+1,r,tree[lroot].r,tree[rroot].r,k-tree[rroot].v+tree[lroot].v);
	}
}

void fuck()
{
	int i,l,r,k;
	T_cnt=0;
	tree[0].l=tree[0].r=tree[0].v=0;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	t=unique(b+1,b+n+1)-b-1;
	for(i=1;i<=n;i++){
		root[i]=t_update(1,get_pos(a[i]),1,t,root[i-1]);
		printf("\n");
	}
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&l,&r,&k);
		int p=t_query(root[l-1],root[r],1,t,k);
		printf("%d\n",b[p]);
	}
}

int main()
{
	while(~scanf("%d%d",&n,&m)) fuck();
 return 0;
}

