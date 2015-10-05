#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int l,r,v;
}tree[300000];
int n,m,a[50010];
long long p;
void t_build(int l,int r,int rt)
{
	int m=(l+r)>>1;
	tree[rt].l=l;tree[rt].r=r;tree[rt].v=0;
	if(l==r) return;
	t_build(l,m,rt<<1);
	t_build(m+1,r,rt<<1|1);
}

void Pushdown(int rt)
{
	tree[rt<<1].v+=tree[rt].v;
	tree[rt<<1|1].v+=tree[rt].v;
	tree[rt].v=0;
}

void t_add(int v,int l,int r,int rt)
{
	int m=(tree[rt].l+tree[rt].r)>>1;
	if(tree[rt].l==l&&tree[rt].r==r){
		tree[rt].v+=v;
		return;
	}
	Pushdown(rt);
	if(r<=m) t_add(v,l,r,rt<<1);
	else if(l>m) t_add(v,l,r,rt<<1|1);
	else{
		t_add(v,l,m,rt<<1);
		t_add(v,m+1,r,rt<<1|1);
	}
}

void t_DFS(int rt)
{
	if(tree[rt].l==tree[rt].r){
		if(tree[rt].v>=3) p+=(tree[rt].v*(tree[rt].v-1)*(tree[rt].v-2))/6;
		return;
	}
	Pushdown(rt);
	t_DFS(rt<<1);
	t_DFS(rt<<1|1);
}

long long gcd(long long x,long long y)
{
	if(y==0) return x;
	else return gcd(y,x%y);
}

void fuck()
{
	int i,j,l,r,num[50010]={0};
	long long q,g;
	p=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=m;i++){
		scanf("%d%d",&l,&r);
		num[l]++;num[r+1]--;
	}
	for(i=1;i<=n;i++){
		num[i]+=num[i-1];
		if(num[i]>=3) p+=(long long)num[i]*(num[i]-1)*(num[i]-2)*a[i]/6;
	}
	q=(long long)m*(m-1)*(m-2)/6;
	g=gcd(p,q);
	if(g==q) printf("%lld\n",p/g);
	else printf("%lld/%lld\n",p/g,q/g);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}

