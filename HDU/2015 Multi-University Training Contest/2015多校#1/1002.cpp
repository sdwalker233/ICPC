#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k,a[100010],m1,m2;
bool ok;
struct SegTree{
	int l,r;
	int mx,mn,dif;
}tree[400010];

void t_build(int l,int r,int rt)
{
	int m=(l+r)>>1;
	tree[rt].l=l;tree[rt].r=r;
	if(l==r){
		tree[rt].mn=tree[rt].mx=a[l];
		tree[rt].dif=0;
		return;
	}
	t_build(l,m,rt<<1);
	t_build(m+1,r,rt<<1|1);
	tree[rt].mx=max(tree[rt<<1].mx,tree[rt<<1|1].mx);
	tree[rt].mn=min(tree[rt<<1].mn,tree[rt<<1|1].mn);
	tree[rt].dif=tree[rt].mx-tree[rt].mn;
}

int t_query(int l,int r,int rt)
{
	if(!ok) return 0;
	int m=(tree[rt].l+tree[rt].r)>>1;
	//printf(" %d %d %d %d %d\n",l,r,tree[rt].l,tree[rt].r,rt);
	int tmp1=max(m1,tree[rt].mx),tmp2=min(m2,tree[rt].mn);
	if(tree[rt].l==l&&tree[rt].r==r){
		//printf(" %d %d %d %d %d\n",l,r,tree[rt].l,tree[rt].r,rt);
		if(tmp1-tmp2<k){
			m1=tmp1;m2=tmp2;
			return tree[rt].r;
		}
		else{
			//printf("1aaaa\n");
			if(tree[rt].l==tree[rt].r) return ok=0;
			return max(t_query(m+1,r,rt<<1|1),t_query(l,m,rt<<1));
		}
	}
	if(m>=r) return t_query(l,r,rt<<1);
	if(m<l) return t_query(l,r,rt<<1|1);
	return max(t_query(m+1,r,rt<<1|1),t_query(l,m,rt<<1));
	//printf(" %d %d %d %d %d\n",l,r,tree[rt].l,tree[rt].r,rt);
}

void fuck()
{
	int i,p1,p2;
	long long ans=0;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	a[n+1]=0x7fffffff;
	t_build(1,n,1);
	for(i=1;i<=n;i++){
		m1=m2=a[i];ok=1;
		p1=t_query(i,n,1);
		ans+=p1-i+1;
		//printf("  %d %d %d %d\n",i,p1,m1,m2);
	}
	cout<<ans<<endl;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		fuck();
 return 0;
}

