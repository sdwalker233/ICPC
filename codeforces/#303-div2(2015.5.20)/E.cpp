#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define MAXN 300010
using namespace std;
struct node{
	int to,next,v;
}edge[1000000];
int tot=0,head[MAXN];

void addedge(int x,int y,int z)
{
	++tot;
	addedge[tot].to=y;
	addedge[tot].v=z;
	addedge[tot].next=head[x];
	head[x]=tot;
}

void dijkstra()
{
	int dis[MAXN],i,j;
	priority_queue q;
}

int main()
{
	int n,m,i;
	memset(head,-1,sizeof(head));
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y,&z);
		addedge(x,y,z);
		addedge(y,x,z);
	}
 return 0;
}

