#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define MAXN 2010
using namespace std;
map<int,int> mp;
map<int,int>::iterator it;
struct SegTree{
	int l,r,col;
}tree[MAXN<<4],op[MAXN<<2];
int n,lastpos,lastcol,ans,ansl,ansr,f[MAXN<<2];

void PushDown(int rt)
{
	if(tree[rt].col){
		tree[rt<<1].col=tree[rt].col;
		tree[rt<<1|1].col=tree[rt].col;
	}
}

void PushUp(int rt)
{
	if(tree[rt<<1].col==tree[rt<<1|1].col)
		tree[rt].col=tree[rt<<1].col;
	else tree[rt].col=0;
}

void t_build(int l,int r,int rt)
{
	int m=(l+r)>>1;
	tree[rt].l=l;tree[rt].r=r;tree[rt].col=1;
	if(l==r) return;
	t_build(l,m,rt<<1);
	t_build(m+1,r,rt<<1|1);
}

void t_update(int col,int l,int r,int rt)
{
	//printf("%d %d %d %d\n",l,r,tree[rt].l,tree[rt].r);
	int m=(tree[rt].l+tree[rt].r)>>1;
	if(l==tree[rt].l&&r==tree[rt].r){
		tree[rt].col=col;
		return;
	}
	PushDown(rt);
	if(r<=m) t_update(col,l,r,rt<<1);
	else if(l>m) t_update(col,l,r,rt<<1|1);
	else {
		t_update(col,l,m,rt<<1);
		t_update(col,m+1,r,rt<<1|1);
	}
	PushUp(rt);
}

void t_travel(int rt)
{
	if(tree[rt].col){
		if(lastcol!=tree[rt].col){
			lastpos=tree[rt].l;
			lastcol=tree[rt].col;
		}
		if(lastcol==2&&ans<f[tree[rt].r+1]-f[lastpos]){
			ans=f[tree[rt].r+1]-f[lastpos];
			ansl=f[lastpos];
			ansr=f[tree[rt].r+1]-1;
		}
		//printf("%d\n",tree[rt].col);
		return;
	}
	PushDown(rt);
	t_travel(rt<<1);
	t_travel(rt<<1|1);
}

void fuck()
{
	int i,a,b,cnt=0;
	char s[5];
	if(n==0){
		printf("Oh, my god\n");
		return;
	}
	mp.clear();
	for(i=1;i<=n;i++){
		scanf("%d%d%s",&op[i].l,&op[i].r,&s);
		op[i].l--;
		op[i].col=(s[0]=='b')?1:2;
		mp.insert(make_pair(op[i].l,1));
		mp.insert(make_pair(op[i].r,1));
	}
	
	for(it=mp.begin();it!=mp.end();it++){
		(*it).second=++cnt;
		f[cnt]=(*it).first;
	}
	t_build(1,cnt,1);
	
	for(i=1;i<=n;i++){
		t_update(op[i].col,mp[op[i].l],mp[op[i].r]-1,1);
	}
	ans=lastcol=0;
	lastpos=1;
	t_travel(1);
	if(ans==0) printf("Oh, my god\n");
	else printf("%d %d\n",ansl+1,ansr+1);
}

int main()
{
	while(~scanf("%d",&n))
		fuck();
 return 0;
}