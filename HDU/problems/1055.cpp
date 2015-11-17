#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 1010
using namespace std;
struct node
{
	int p,mark;
	double v;
	node(int _p=0,double _v=0,int _mark=0)
	{
		p=_p;v=_v;mark=_mark;
	}
	friend bool operator<(const node& x,const node& y)
	{
		return x.v<y.v;
	}
};
int n,r,v[MAXN],fa[MAXN],mark[MAXN],vis[MAXN],t[MAXN];

int find(int x)
{
	if(vis[fa[x]]==0) return fa[x];
	return fa[x]=find(fa[x]);
}

void fuck()
{
	int i,a,b,pre;
	int ans=0;
	node now;
	priority_queue<node> q;
	memset(mark,0,sizeof(mark));
	memset(vis,0,sizeof(vis));
	fa[r]=0;
	for(i=1;i<=n;i++)
		scanf("%d",&v[i]);
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		fa[b]=a;
	}
	for(i=1;i<=n;i++){
		q.push(node(i,v[i],0));
		t[i]=1;
		ans+=v[i];
	}
	while(!q.empty()){
		now=q.top();
		q.pop();
		if(now.p==r||now.mark<mark[now.p]) continue;
		pre=find(now.p);
		//printf(" %d\n",now.p);
		ans+=v[now.p]*t[pre];
		v[pre]+=v[now.p];
		t[pre]+=t[now.p];
		q.push(node(pre,(double)v[pre]/t[pre],++mark[pre]));
		vis[now.p]=1;
	}
	printf("%d\n",ans);
}

int main()
{
	while(~scanf("%d%d",&n,&r)&&n&&r)
		fuck();
 return 0;
}