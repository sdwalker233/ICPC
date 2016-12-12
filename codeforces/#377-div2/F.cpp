#include <bits/stdc++.h>
#define MAXN 400010
using namespace std;
int n,m;
struct E{
	int to,next;
}edge[MAXN<<1];
int head[MAXN],tot,fa[MAXN],low[MAXN],dfn[MAXN],tim,sc[MAXN];
int size[MAXN],x[MAXN],y[MAXN];
int bridge[MAXN],vis[MAXN];
set<pair<int,int> > st;

void addedge(int x,int y)
{
	++tot;
	edge[tot].to=y;
	edge[tot].next=head[x];
	head[x]=tot;
}

void tarjan(int x,int pre)
{
    int v,i;
    dfn[x]=low[x]=++tim;
	fa[x]=pre;
    for(i=head[x];~i;i=edge[i].next){
        v=edge[i].to;
		if(v==pre) continue;
        if(dfn[v]==0){
            tarjan(v,x);
            low[x]=min(low[x],low[v]);
			if(low[v]>dfn[x]){
				bridge[v]=x;
				bridge[x]=v;
				//printf("  %d %d\n",x,v);
			}
		}
        else low[x]=min(low[x],dfn[v]);
    }
}

void DFS1(int x,int c)
{
	int i;
	sc[x]=c;vis[x]=1;size[c]++;
	for(i=head[x];~i;i=edge[i].next){
		int v=edge[i].to;
		if(vis[v]) continue;
		if(bridge[x]==v||bridge[v]==x) DFS1(v,++tim);
		else DFS1(v,c);
	}
}

void DFS2(int x,int pre)
{
	int i;
	vis[x]=1;
	for(i=head[x];~i;i=edge[i].next){
		int v=edge[i].to;
		if(v==pre) continue;
		//printf(" %d %d %d %d\n",x,v,bridge[x],bridge[v]);
		if(st.find(make_pair(v,x))==st.end())
			st.insert(make_pair(x,v));
		if(!vis[v]) DFS2(v,x);
	}
}

int main()
{
	int i;
	memset(head,-1,sizeof(head));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&x[i],&y[i]);
		addedge(x[i],y[i]);
		addedge(y[i],x[i]);
	}
	tarjan(1,0);
	memset(vis,0,sizeof(vis));
	tim=1;
	DFS1(1,1);
	int maxc=1,ans;
	for(i=1;i<=n;i++)
		if(size[i]>size[maxc]) maxc=i;
	ans=size[maxc];
	for(i=1;i<=n;i++)
		if(sc[i]==maxc) break;
	memset(vis,0,sizeof(vis));
	DFS2(i,0);
	printf("%d\n",ans);
	for(i=1;i<=m;i++){
		if(st.find(make_pair(y[i],x[i]))!=st.end())
			printf("%d %d\n",x[i],y[i]);
		else printf("%d %d\n",y[i],x[i]);
	}
 return 0;
}

