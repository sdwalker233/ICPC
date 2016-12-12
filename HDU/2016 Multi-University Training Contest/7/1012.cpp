#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 50010
using namespace std;
struct point{
	int x,y;
}a[500010];
struct Segtree{
	int l,r;
	int mx;
}tree[MAXN<<2];
int n;

void t_build(int l,int r,int rt)
{
	int m=(l+r)>>1;
	tree[rt].l=l;tree[rt].r=r;
	tree[rt].mx=0;
	if(l==r) return;
	t_build(l,m,rt<<1);
	t_build(m+1,r,rt<<1|1);
}

int t_query(int l,int r,int rt)
{
	int m=(tree[rt].l+tree[rt].r)>>1;
	if(tree[rt].l==l&&tree[rt].r==r) return tree[rt].mx;
	if(m>=r) return t_query(l,r,rt<<1);
	if(m<l) return t_query(l,r,rt<<1|1);
	return max(t_query(l,m,rt<<1),t_query(m+1,r,rt<<1|1));
}

void t_update(int p,int v,int rt)
{
	int m=(tree[rt].l+tree[rt].r)>>1;
	tree[rt].mx=max(tree[rt].mx,v);
	if(tree[rt].l==tree[rt].r) return; 
	if(m>=p) t_update(p,v,rt<<1);
	else t_update(p,v,rt<<1|1);
}

bool cmp1(const point& x,const point& y)
{
	if(x.x==y.x) return x.y<y.y;
	return x.x<y.x;
}

bool cmp2(const point& x,const point& y){
	if(x.x==y.x) return x.y>y.y;
	return x.x<y.x;
}

bool fuck()
{
	int i,x,y;
	for(i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	sort(a+1,a+n+1,cmp1);
	int cnt=1;
	for(i=2;i<=n;i++){
		if(a[i].x!=a[i-1].x||a[i].y!=a[i-1].y) a[++cnt]=a[i];
	}
	n=cnt;
	t_build(1,50000,1);
	t_update(a[1].y,a[1].x,1);
	for(i=2;i<=n;i++){
		x=t_query(a[i].y,a[i].y,1)+1;
		y=(a[i].x==a[i-1].x)?a[i-1].y+1:1;
		if(x==1&&y==1){
			if(t_query(1,a[i].y,1)) return 0;
		}
		//printf(" %d %d %d %d %d\n",x,y,a[i].x,a[i].y,t_query(y,a[i].y,1));
		if(t_query(y,a[i].y,1)>=x) return 0;
		t_update(a[i].y,a[i].x,1);
	}
	sort(a+1,a+n+1,cmp2);
	t_build(1,50000,1);
	t_update(a[1].y,a[1].x,1);
	for(i=2;i<=n;i++){
		x=t_query(a[i].y,a[i].y,1)+1;
		y=(a[i].x==a[i-1].x)?a[i-1].y-1:50000;
		//printf(" %d %d %d %d\n",x,y,a[i].x,a[i].y);
		if(x==1&&y==50000){
			if(t_query(a[i].y,50000,1)) return 0;
		}
		if(t_query(a[i].y,y,1)>=x) return 0;
		t_update(a[i].y,a[i].x,1);
	}
	return 1;
}

int main()
{
	while(~scanf("%d",&n)&&n)
		if(fuck()) puts("YES");
		else puts("NO");
 return 0;
}

