#include<iostream>
#include<cstdio>
#include<algorithm>
#define mod 0x7fffffff80000000
#define ull unsigned long long
#define MAXN 100010
using namespace std;
struct Segtree{
	int l,r;
	ull v,sum;
	bool ok;
}tree[MAXN*5];
int n,q;
ull a[MAXN];

ull Mul(ull a,ull b)
{
	ull tmp=a,ans=0;
	while(b){
		if(b&1){
			ans+=tmp;
			if(ans>=mod) ans-=mod;
		}
		tmp*=2;
		if(tmp>=mod) tmp-=mod;
		b>>=1;
	}
	return ans;
}

 void PushUp(int rt)
 {
 	tree[rt].sum=tree[rt<<1].sum+tree[rt<<1|1].sum;
 	if(tree[rt].sum>=mod) tree[rt].sum-=mod;
 	tree[rt].ok=(tree[rt<<1].ok&&tree[rt<<1|1].ok);
 }

 void t_build(int l,int r,int rt)
 {
 	int m=(l+r)>>1;
 	tree[rt].l=l;tree[rt].r=r;
 	if(l==r){
 		tree[rt].v=tree[rt].sum=a[l];
 		if(Mul(a[l],a[l])==a[l]) tree[rt].ok=1;
 		else tree[rt].ok=0;
 		return;
 	}
 	t_build(l,m,rt<<1);
 	t_build(m+1,r,rt<<1|1);
 	PushUp(rt);
 }

 ull t_query(int l,int r,int rt)
 {
 	int m=(tree[rt].l+tree[rt].r)>>1;
 	if(tree[rt].l==l&&tree[rt].r==r) return tree[rt].sum;
 	if(m>=r) return t_query(l,r,rt<<1);
	if(m<l) return t_query(l,r,rt<<1|1);
	return (t_query(l,m,rt<<1)+t_query(m+1,r,rt<<1|1))%mod;
 }

 void t_change(int l,int r,int rt)
 {
 	int m=(tree[rt].l+tree[rt].r)>>1;
 	if(tree[rt].ok) return;
 	if(tree[rt].l==tree[rt].r){
 		ull tmp=Mul(tree[rt].v,tree[rt].v);
 		if(tmp==tree[rt].v) tree[rt].ok=1;
 		else tree[rt].v=tree[rt].sum=tmp;
 		return;
 	}
 	if(m>=r) t_change(l,r,rt<<1);
	else if(m<l) t_change(l,r,rt<<1|1);
	else{
		t_change(l,m,rt<<1);
		t_change(m+1,r,rt<<1|1);
	}
	PushUp(rt);
 }

 void fuck()
 {
 	int i,x,y;
 	ull ans=0;
 	scanf("%d%d",&n,&q);
 	for(i=1;i<=n;i++){
 		scanf("%llu",&a[i]);
 	}
 	t_build(1,n,1);
 	for(i=1;i<=q;i++){
 		scanf("%d%d",&x,&y);
 		ans=(ans+t_query(x,y,1))%mod;
 		printf("%llu\n",ans);
 		t_change(x,y,1);
 	}
 }

int main()
{
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		printf("Case #%d:\n",i);
		fuck();
	}
 return 0;
}

