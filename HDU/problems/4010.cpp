#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 300010
using namespace std;
struct Edge{
	int to,nxt;
}edge[MAXN<<1];
int head[MAXN],tot;
int fa[MAXN];
int n;

void DFS(int x,int pre)
{
	int i;
	for(i=head[x];~i;i=edge[x].nt){
		if(edge[x].to=pre) continue;
		fa[edge[x].to]=x;
		DFS(edge[x].to,x);
	}
}

void addedge(int x,int y)
{
	++tot;
	edge[tot].to=y;
	edge[tot].nxt=head[x];
	head[x]=tot;
}

void init()
{
	tot=0;
	memset(head,-1,sizeof(head));
}

void fuck()
{
	int i,x,y,x,op;
	init();
	for(i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
}

int main()
{
	while(~scanf("%d",&n)) fuck();
 return 0;
}

