#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 100010
using namespace std;
struct node{
	int l,r;
	long long v;
}tree[MAXN<<2];
int n,mod,op[MAXN],num[MAXN],a[MAXN],len1,p[MAXN],b[MAXN],len2;

void t_build(int l,int r,int rt)
{
	int m=(l+r)>>1;
	tree[rt].l=l;tree[rt].r=r;
	if(l==r){
		tree[rt].v=a[l]%mod;
		return;
	}
	t_build(l,m,rt<<1);
	t_build(m+1,r,rt<<1|1);
	tree[rt].v=(tree[rt<<1].v*tree[rt<<1|1].v)%mod;
}

long long t_query(int l,int r,int rt)
{
	int m=(tree[rt].l+tree[rt].r)>>1;
	if(l==tree[rt].l&&tree[rt].r==r) return tree[rt].v;
	if(m>=r) return t_query(l,r,rt<<1);
	if(m<l) return t_query(l,r,rt<<1|1);
	return (t_query(l,m,rt<<1)*t_query(m+1,r,rt<<1|1))%mod;
}

void t_update(int v,int p,int rt)
{
	int m=(tree[rt].l+tree[rt].r)>>1;
	if(tree[rt].l==tree[rt].r){
		tree[rt].v=v;
		return;
	}
	if(m>=p) t_update(v,p,rt<<1);
	else t_update(v,p,rt<<1|1);
	tree[rt].v=(tree[rt<<1].v*tree[rt<<1|1].v)%mod;
}

void fuck()
{
	int i,pp;
	scanf("%d%d",&n,&mod);
	len1=len2=0;
	for(i=1;i<=n;i++){
		scanf("%d%d",&op[i],&num[i]);
		if(op[i]==1){
			a[++len1]=num[i];
			p[i]=len1;
		}
		else{
			b[i]=p[num[i]];
		}
	}
	t_build(1,len1,1);
	for(i=1;i<=n;i++){
		if(op[i]==1){
			printf("%I64d\n",t_query(1,p[i],1));
			pp=p[i];
		}
		else{
			t_update(1,b[i],1);
			printf("%I64d\n",t_query(1,pp,1));
		}
	}
}

int main()
{
	int t=0,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		printf("Case #%d:\n",i);
		fuck();
	}
 return 0;
}

