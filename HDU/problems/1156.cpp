#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 200010
using namespace std;
struct SegTree{
	int v;
	int l,r;
}tree[MAXN<<2];
struct node{
	int x,y;
}p[MAXN];
int n,a[MAXN],up[MAXN],down[MAXN],line[MAXN];
int minn1[MAXN],minn2[MAXN],ans[MAXN],cnt2;

bool cmpx(const node& x,const node& y)
{
	if(x.x==y.x) return x.y>y.y;
	return x.x<y.x;
}

bool cmpy(const node& x,const node& y)
{
	return x.y<y.y;
}

void PushUp(int rt)
{
	tree[rt].v=tree[rt<<1].v+tree[rt<<1|1].v;
}

void t_build(int l,int r,int rt)
{
	int m=(l+r)>>1;
	tree[rt].l=l;tree[rt].r=r;tree[rt].v=0;
	if(l==r) return;
	t_build(l,m,rt<<1);
	t_build(m+1,r,rt<<1|1);
}

int t_query(int l,int r,int rt)
{
	int m=(tree[rt].l+tree[rt].r)>>1;
	if(l>r) return 0;
	if(tree[rt].l==l&&tree[rt].r==r) return tree[rt].v;
	//if(tree[rt].l>=tree[rt].r) return tree[rt].v;
	if(m>=r) return t_query(l,r,rt<<1);
	if(m<l) return t_query(l,r,rt<<1|1);
	return t_query(l,m,rt<<1)+t_query(m+1,r,rt<<1|1);
}

void t_add(int val,int pos,int rt)
{
	int m=(tree[rt].l+tree[rt].r)>>1;
	if(tree[rt].l>=tree[rt].r){
		tree[rt].v+=val;
		return;
	}
	if(pos<=m) t_add(val,pos,rt<<1);
	else t_add(val,pos,rt<<1|1);
	PushUp(rt);
}

void fuck()
{
	int i,last,num=0,n1,n2,num2=0,cnt;
	int maxn1=0,maxn2,maxx;
	int tmp1,tmp2,tmp3,tmp4;
	memset(a,0,sizeof(a));
	memset(up,0,sizeof(up));
	memset(down,0,sizeof(down));
	memset(line,0,sizeof(line));
	cnt2=0;
	for(i=1;i<=n;i++)
		scanf("%d%d",&p[i].x,&p[i].y);
	sort(p+1,p+n+1,cmpy);
	last=0x7fffffff;
	for(i=1;i<=n;i++){
		if(p[i].y!=last){
			last=p[i].y;
			num++;
		}
		p[i].y=num;
		a[num]++;
	}
	for(i=1;i<=num;i++) up[i]=up[i-1]+a[i];
	for(i=num;i>=1;i--) down[i]=down[i+1]+a[i];
	
	sort(p+1,p+n+1,cmpx);
	last=0x7fffffff;
	for(i=1;i<=n;i++){
		if(p[i].x!=last){
			last=p[i].x;
			num2++;
			minn1[num2]=0x7fffffff;
		}
		p[i].x=num2;
		line[num2]++;
	}
	/*
	for(i=1;i<=n;i++){
		printf(" %d %d\n",p[i].x,p[i].y);
	}
	*/
	t_build(1,num,1);
	
	last=0x7fffffff;
	for(i=1;i<=n;i++){
		t_add(1,p[i].y,1);
		if(p[i].y!=last){
			last=p[i].y;
		}
		tmp1=t_query(1,p[i].y-1,1);
		tmp2=t_query(p[i].y+1,num,1);
		tmp3=up[p[i].y-1];
		tmp4=down[p[i].y+1];
		cnt=line[p[i].x];
		n1=tmp1+tmp4-tmp2;
		n2=tmp3-tmp1+tmp2-cnt+1;
		//printf(" %d %d %d %d %d %d %d %d\n",p[i].x,p[i].y,n1,n2,tmp1,tmp2,tmp3,tmp4);
		if(n1<minn1[p[i].x]){
			minn1[p[i].x]=n1;
			minn2[p[i].x]=n2;
		}
	}
	for(i=1;i<=num2;i++)
		maxn1=max(maxn1,minn1[i]);
	printf("Stan: %d; Ollie:",maxn1);
	for(i=1;i<=num2;i++)
		if(minn1[i]==maxn1) ans[++cnt2]=minn2[i];
	sort(ans+1,ans+1+cnt2);
	cnt2=unique(ans+1,ans+1+cnt2)-ans-1;
	for(i=1;i<=cnt2;i++) printf(" %d",ans[i]);
	printf(";\n");
}

int main()
{
	//freopen("E.1.dat","r",stdin);
	//freopen("out.txt","w",stdout);
	while(~scanf("%d",&n)&&n)
		fuck();
 return 0;
}

