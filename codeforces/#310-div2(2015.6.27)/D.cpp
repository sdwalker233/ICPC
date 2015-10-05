#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
struct node1{
	long long l;
	int num;
	node1(long long _l=INF,int _num=0){
		l=_l;
		num=_num;
	}
}a[20010];
struct node2{
	long long mn,mx;
	int num,bridge;
	friend bool operator<(node2 &x,node2 &y){
		return x.mx>y.mx;
	}
}b[20010];
struct Segtree{
	int l,r,p;
	long long mn;
}tree[100000];
long long l[200010],r[200010];
int n,m,pos[20010];

bool cmp1(node1 &x,node1 &y)
{
	return x.l<y.l;
}

bool cmp2(node2 &x,node2 &y)
{
	return x.mx<y.mx;
}

bool cmp3(node2 &x,node2 &y)
{
	return x.num<y.num;
}

void t_build(int l,int r,int rt)
{
	int m=(l+r)>>1;
	tree[rt].l=l;tree[rt].r=r;
	if(l==r){
		tree[rt].mn=a[l].l;
		tree[rt].p=l;
		pos[l]=rt; 
		return;
	}
	t_build(l,m,rt<<1);
	t_build(m+1,r,rt<<1|1);
	tree[rt].mn=tree[rt<<1].mn;
	tree[rt].p=tree[rt<<1].p;
}

node1 find_min(int x,int rt)
{
	if(tree[rt].l==tree[rt].r)
		if(tree[rt].mn>=x) return node1(tree[rt].mn,tree[rt].p);
		else return node1(INF,0);
	if(tree[rt].mn>=x) return node1(tree[rt].mn,tree[rt].p);
	node1 tmp1=find_min(x,rt<<1);
	node1 tmp2=find_min(x,rt<<1|1);
	if(tmp1.l<tmp2.l) return tmp1;
	else return tmp2;
}

void del(int x,int rt)
{
	int m=(tree[rt].l+tree[rt].r)>>1;
	if(tree[rt].l==tree[rt].r){
		tree[rt].mn=INF;
		return;
	}
	if(x<=m) del(x,rt<<1);
	else del(x,rt<<1|1);
	if(tree[rt<<1].mn<tree[rt<<1|1].mn){
		tree[rt].mn=tree[rt<<1].mn;
		tree[rt].p=tree[rt<<1].p;
	}
	else{
		tree[rt].mn=tree[rt<<1|1].mn;
		tree[rt].p=tree[rt<<1|1].p;
	}
}
int main()
{
	int i;
	bool ok=0;
	node1 tmp;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%I64d%I64d\n",&l[i],&r[i]);
	for(i=1;i<=m;i++){
		scanf("%I64d",&a[i].l);
		a[i].num=i;
	}
	for(i=1;i<n;i++){
		if(r[i]<=l[i+1]) b[i].mn=l[i+1]-r[i];
		else b[i].mn=0;
		b[i].mx=r[i+1]-l[i];
		b[i].num=i;
	}
	sort(a+1,a+n+1,cmp1);
	sort(b+1,b+n,cmp2);
	t_build(1,n-1,1);
	for(i=1;i<n;i++){
		tmp=find_min(b[i].mn,1);
		if(tmp.num==0){
			ok=1;
			break;
		}
		b[i].bridge=tmp.num;
		del(tmp.num,1);
	}
	if(ok==1) printf("No\n");
	else {
		sort(b+1,b+n,cmp3);
		printf("Yes\n");
		for(i=1;i<n;i++)
			printf("%d ",b[i].bridge);
	}
 return 0;
}

