#include<bits/stdc++.h>
using namespace std;
struct node{
	int next,to;
}edge[200010];
int tot=-1;
int x[100010],y[100010],fa[100010],head[100010];
bool vis[100010]={0},loop[100010]={0};

int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}

void unio(int x,int y)
{
	int fx=find(x),fy=find(y);
	fa[fx]=fy;
}

void add_edge(int x,int y)
{
	++tot;
	edge[tot].to=y;
	edge[tot].next=head[x];
	head[x]=tot;
}

void DFS(int x,int from)
{
	int i;
	if(vis[x]==1){
		loop[x]=1;
		return;
	}
	vis[x]=1;
	for(i=head[x];~i;i=edge[i].next){
		if(edge[i].to==from) continue;
		DFS(edge[i].to,x);
		if(loop[edge[i].to]) loop[x]=1;
	}
}

int main()
{
    int n,m,i;
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof(head));
	for(i=1;i<=n;i++) fa[i]=i;
	for(i=1;i<=m;i++){
		scanf("%d%d",&x[i],&y[i]);
		add_edge(x[i],y[i]);
		add_edge(y[i],x[i]);
	}
	for(i=1;i<=n;i++)
		if(!vis[i]) DFS(i,-1);
	for(i=1;i<=m;i++) unio(x[i],y[i]);
	for(i=1;i<=n;i++)
		if(loop[i]) loop[find(i)]=1;
	int cnt=0;
	set<int> st;
	for(i=1;i<=n;i++){
		if(loop[find(i)]==0) st.insert(find(i));
	}
	printf("%d\n",st.size());
 return 0;
}

